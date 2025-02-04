# Piotr Hernik

module blocksys

export sparseGaussianSolve!, sparseFactorizeLU!, solveUsingSparseLU!

using Main.sparseModule

#     sparseGaussianSolve!(A::MySparseMatrix, b::Vector{Float64}, usePivoting::Bool)::Vector{Float64}

# Description:
#     This function solves a system of linear equations using the Gaussian elimination method optimized for sparse matrices. The function modifies the input matrix during execution.

# Arguments:
#     A::MySparseMatrix: Sparse matrix representing the coefficients of the linear system.
#     b::Vector{Float64}: Right-hand side vector.
#     usePivoting::Bool: If true, performs partial pivoting to improve numerical stability.

# Returns:
#     Vector{Float64}: Solution vector to the system.

function sparseGaussianSolve!(A::MySparseMatrix, b::Vector{Float64}, usePivoting::Bool)::Vector{Float64}
    return usePivoting ? gaussianWithPivot!(A, b) : gaussianWithoutPivot!(A, b)
end

function gaussianWithoutPivot!(A::MySparseMatrix, b::Vector{Float64})::Vector{Float64}

    n = A.size

    for i in 1:n-1
        for j in i+1:getNonZeroRowsBelow(A, i)

            try
                factor = A[j, i] / A[i, i]
                A[j, i] = 0.0

                for k in i+1:getNonZeroColumnsRight(A, i)
                    A[j, k] -= factor * A[i, k]
                end

                b[j] -= factor * b[i]

            catch DivideError
                println("Zero detected at diagonal entry ($i, $i); $(A[i, i])")
            end
        end
    end

    x = zeros(n)
    x[n] = b[n] / A[n, n]

    for i in n-1:-1:1
        x[i] = b[i]

        for j in i+1:getNonZeroColumnsRight(A, i)
            x[i] -= A[i, j] * x[j]
        end
        
        x[i] /= A[i, i]
    end

    return x
end

function gaussianWithPivot!(A::MySparseMatrix, b::Vector{Float64})::Vector{Float64}
    
    n = A.size
    p = [1:n;]

    for i in 1:n-1

        pivotRow = reduce((x, y) -> abs(A[p[x], i]) >= abs(A[p[y], i]) ? x : y, i:getNonZeroRowsBelow(A, i))
        p[i], p[pivotRow] = p[pivotRow], p[i]

        for j in i+1:getNonZeroRowsBelow(A, i)

            try
                factor = A[p[j], i] / A[p[i], i]
                A[p[j], i] = 0.0

                for k in i+1:getNonZeroColumnsRight(A, j + A.blockSize)
                    A[p[j], k] -= factor * A[p[i], k]
                end

                b[p[j]] -= factor * b[p[i]]

            catch DivideError
                println("Zero detected at diagonal entry ($i, $i); $(A[i, i])")
            end
        end
    end

    x = zeros(n)
    x[n] = b[p[n]] / A[p[n], n]

    for i in n-1:-1:1
        x[i] = b[p[i]]

        for j in i+1:getNonZeroColumnsRight(A, i + A.blockSize)
            x[i] -= A[p[i], j] * x[j]
        end
        
        x[i] /= A[p[i], i]
    end

    return x    
end

#     sparseFactorizeLU!(A::MySparseMatrix)

# Description:
#     This function computes the LU decomposition of the matrix A. Optimized for sparse matrices and takes O(n) time. The decomposition will be stored in the matrix A. It returns the permutation vector p.

function sparseFactorizeLU!(A::MySparseMatrix, pivot::Bool)::Vector{Int}
    return pivot ? performLUWithPivot!(A) : performLUWithoutPivot!(A)
end

function performLUWithoutPivot!(A::MySparseMatrix)

    n = A.size

    for i in 1:n-1
        for j in i+1:getNonZeroRowsBelow(A, i)

            try
                f = A[j, i] / A[i, i]
                A[j, i] = f
                A.LU_size += 1

                for k in i+1:getNonZeroColumnsRight(A, i)
                    A[j, k] -= f * A[i, k]
                    A.LU_size += 1
                end

            catch DivideError
                println("Zero encountered on diagonal at ($i, $i); value: $(A[i, i])")
            end

        end
    end

    return [1:n;]
end

function performLUWithPivot!(A::MySparseMatrix)
    
    n = A.size
    p = [1:n;]

    for i in 1:n-1

        q = reduce((x, y) -> abs(A[p[x], i]) >= abs(A[p[y], i]) ? x : y, i:getNonZeroRowsBelow(A, i))
        p[i], p[q] = p[q], p[i]

        for j in i+1:getNonZeroRowsBelow(A, i)

            try
                f = A[p[j], i] / A[p[i], i]
                A[p[j], i] = f
                A.LU_size += 1

                for k in i+1:getNonZeroColumnsRight(A, i + A.blockSize)
                    A[p[j], k] -= f * A[p[i], k]
                    A.LU_size += 1
                end

            catch DivideError
                println("Zero encountered on diagonal at ($i, $i); value: $(A[i, i])")
            end
        end
    end

    return p
end


#     solveUsing_LU!(A::MySparseMatrix, b::Vector{Float64}, pivot::Bool)::Vector{Float64}

# Description:
#     This function solves the system of linear equations using the LU decomposition method. Optimized for sparse matrices and takes O(n) time. Vector b will be modified in the process.

# Arguments:
#     A::MySparseMatrix: Sparse matrix.
#     b::Vector{Float64}: Right hand side vector.
#     pivot::Bool: If true, the function uses the partial pivoting method.

function solveUsingSparseLU!(A::MySparseMatrix, b::Vector{Float64}, pivot::Bool)::Vector{Float64}
    return pivot ? solveUsing_LU_withPivot(A, b) : solveUsing_LU_withoutPivot(A, b)
end

function solveUsing_LU_withoutPivot(A::MySparseMatrix, b::Vector{Float64})::Vector{Float64}
    
    performLUWithoutPivot!(A)
    n = A.size

    for i in 1:n-1
        for j in i+1:getNonZeroRowsBelow(A, i)
            b[j] -= A[j, i] * b[i]
        end
    end

    x = zeros(n)
    for i in n:-1:1
        x[i] = b[i]

        for j in i+1:getNonZeroColumnsRight(A, i)
            x[i] -= A[i, j] * x[j]
        end

        x[i] /= A[i, i]
    end

    return x
end

function solveUsing_LU_withPivot(A::MySparseMatrix, b::Vector{Float64})::Vector{Float64}

    p = performLUWithPivot!(A)
    n = A.size

    for i in 2:n
        for j in getNonZeroColumnsLeft(A, p[i]):i-1
            b[p[i]] -= A[p[i], j] * b[p[j]]
        end
    end

    x = zeros(n)
    x[n] = b[p[n]] / A[p[n], n]

    for i in n-1:-1:1
        x[i] = b[p[i]]

        for j in i+1:getNonZeroColumnsRight(A, i + A.blockSize)
            x[i] -= A[p[i], j] * x[j]
        end

        x[i] /= A[p[i], i]
    end

    return x
end

end # modul
