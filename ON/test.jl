module SparseMatrixModule

using Printf

export SparseMatrix, readMatrixFromFile, getTopRow, getBottomRow, getLeftColumn, getRightColumn, printSystem


mutable struct SparseMatrix
    data::Dict{Tuple{Int, Int}, Float64}
    size::Int
    numberOfBlocks::Int
    blockSize::Int
    numberOfNonZero::Int
    numberOfRefrences::Int
    LU_size::Int

    # Constructor
    function SparseMatrix(data::Dict{Tuple{Int, Int}, Float64}, n::Int, v::Int, l::Int, numberOfNonZero::Int)
        new(data, n, v, l, numberOfNonZero, 0, 0)
    end

end

# Define indexing for getting values
function Base.getindex(A::SparseMatrix, i::Int, j::Int)
    A.numberOfRefrences += 1
    get(A.data, (i,j), 0.0)
end

# Define indexing for setting values
function Base.setindex!(A::SparseMatrix, val::Number, i::Int, j::Int)
    A.numberOfRefrences += 1
    A.data[(i,j)] = Float64(val)
end

# Print the matrix
function Base.show(io::IO, A::SparseMatrix)
    red = "\u001b[31m"    
    green = "\u001b[32m"  
    reset = "\u001b[0m"   
    n = A.size

    for i in 1:n
        for j in 1:n
            value = A[i, j]
            formattedValue = @sprintf("%8.2f", value)
            
            if i == j && value != 0.0
                print(io, green * formattedValue * reset * " ")
            elseif value != 0.0
                print(io, red * formattedValue * reset * " ")
            else
                print(io, formattedValue * " ")
            end
        end

        if i != n
            println(io)
        end
    end
end


"""
    readMatrixFromFile(filename::String)::SparseMatrix

Description:
    This function reads a matrix from a file and returns a SparseMatrix object.
"""
function readMatrixFromFile(filename::String)::SparseMatrix
    A, n, l, nonZero = open(filename, "r") do file

        counter = 0
        line = readline(file)
        n, l = parse.(Int, split(line))
        
        data = Dict{Tuple{Int, Int}, Float64}()
        for line in eachline(file)
            isempty(line) && continue
            i, j, value = split(line)
            data[(parse(Int, i), parse(Int, j))] = parse(Float64, value)
            counter +=1
        end
        data, n, l, counter
    end
    
    return SparseMatrix(A, n, div(n, l), l, nonZero)
end

"""
    getTopRow(A::SparseMatrix, k::Int)::Int

Description:
    This function finds the highest nonzero row entry in the column k starting from the top. This takes O(1) time.

"""
function getTopRow(A::SparseMatrix, k::Int)::Int
    return max(1, k - A.blockSize)
end

"""
    getBottomRow(A::SparseMatrix, k::Int)::Int

Description:
    This function finds the highest nonzero row entry in the column k starting from the bottom. This takes O(1) time.

"""
function getBottomRow(A::SparseMatrix, k::Int)::Int
    return min(A.size, A.blockSize * (1 + floor(Int, (k + 1) / A.blockSize)))
end

"""
    getLeftColumn(A::SparseMatrix, r::Int)::Int

Description:
    This function finds the most left nonzero column entry in the row r. This takes O(1) time.

"""
function getLeftColumn(A::SparseMatrix, r::Int)::Int
    return max(1, A.blockSize * floor(Int, (r - 1) / A.blockSize) - 1)
end

"""
    readVectorFromFile(filename::String)::Vector{Float64}

Description:
    This function reads right side vector from filename and returns it.

Arguments:
    filename::String: Path to the file with the vector.

Returns:
    Vector{Float64}: Vector.
"""
function readVectorFromFile(filename::String)::Vector{Float64}

    b = Float64[]

    open(filename, "r") do file

        line = readline(file)
        n = parse(Int, line)
        b = Vector{Float64}(undef, n)

        for i in 1:n
            line = readline(file)
            if isempty(line)
                continue
            end

            b[i] = parse(Float64, line)
        end
    end

    return b
end

"""
    writeSolutionToFile(filename::String, x::Vector{Float64}, error::Float64 = NaN)

Description:
    This function writes the solution vector x to the file filename. If error is provided, it will be written as the first line.

Arguments:
    filename::String: Path to the file.
    x::Vector{Float64}: Solution vector.
    error::Float64: Error value.
"""        
function writeSolutionToFile(filename::String, x::Vector{Float64}, error::Float64 = NaN)

    dir = FilePathsBase.dirname(filename)
    if !isdir(dir)
        mkpath(dir)  
    end

    open(filename, "w") do file
        if !isnan(error)
            println(file, error)
        end
        for i in 1:length(x)
            println(file, x[i])
        end
    end
end


"""
    calculateError(x::Vector{Float64}, solution::Union{Vector{Float64}, Nothing} = nothing)::Float64

Description:
    This function calculates the error of the solution x with respect to the solution vector

Arguments:
    x::Vector{Float64}: Solution vector.
    solution::Vector{Float64}: Solution vector, default value of is [1, 1, ..., 1]
"""
function calculateError(x::Vector{Float64}, solution::Union{Vector{Float64}, Nothing} = nothing)::Float64
    if solution === nothing
        solution = ones(length(x))
    end
    return norm(x - solution) / norm(solution)
end

"""
    calculateRightHandSideVector(A::SparseMatrix, x::Union{Vector{Float64}, Nothing} = nothing)::Vector{Float64}

Description:
    This function calculates the right hand side vector of the system Ax = b.

Arguments:
    A::SparseMatrix: Sparse matrix.
    x::Vector{Float64}: Solution vector, default value of is [1, 1, ..., 1]

"""
function calculateRightHandSideVector(A::SparseMatrix, x::Union{Vector{Float64}, Nothing} = nothing)::Vector{Float64}
    n = A.size

    if x === nothing
        x = ones(n)
    end

    y = zeros(n)

    for i in 1:n
        for j in getLeftColumn(A, i):getRightColumn(A, i)
            y[i] += A[i, j] * x[j]
        end
    end
    return y
end


Bartek
Bartek Łabuz
module Bloksys

export gaussianElimination!, LU_decomposition!, solveUsing_LU!

using Main.SparseMatrixModule


"""
    gaussianElimination!(A::SparseMatrix, b::Vector{Float64}, pivot::Bool)::Vector{Float64}

Description:
    This function solves the system of linear equations using the Gaussian elimination method. Optimized for sparse matrices and takes O(n) time. The matrix will be modified in the process.

Arguments:
    A::SparseMatrix: Sparse matrix.
    b::Vector{Float64}: Right hand side vector.
    pivot::Bool: If true, the function uses the partial pivoting method.

Returns:
    Vector{Float64}: Solution vector.
"""
function gaussianElimination!(A::SparseMatrix, b::Vector{Float64}, pivot::Bool)::Vector{Float64}
    return pivot ? gaussianEliminationWithPivot!(A, b) : gaussianEliminationWithoutPivot!(A, b)
end

function gaussianEliminationWithoutPivot!(A::SparseMatrix, b::Vector{Float64})::Vector{Float64}

    n = A.size

    for i in 1:n-1
        for j in i+1:getBottomRow(A, i)

            try
                f = A[j, i] / A[i, i]
                A[j, i] = 0.0

                for k in i+1:getRightColumn(A, i)
                    A[j, k] -= f * A[i, k]
                end

                b[j] -= f * b[i]

            catch DivideError
                println("Zero at the diagonal entry ($i, $i); $(A[i, i])")
            end
        end
    end

    # Back substitution
    x = zeros(n)
    x[n] = b[n] / A[n, n]

    for i in n-1:-1:1
        x[i] = b[i]

        for j in i+1:getRightColumn(A, i)
            x[i] -= A[i, j] * x[j]
        end
        
        x[i] /= A[i, i]
    end

    return x
end



function gaussianEliminationWithPivot!(A::SparseMatrix, b::Vector{Float64})::Vector{Float64}
    
    n = A.size
    p = [1:n;]

    for i in 1:n-1

        q = reduce((x, y) -> abs(A[p[x], i]) >= abs(A[p[y], i]) ? x : y, i:getBottomRow(A, i))
        p[i], p[q] = p[q], p[i]

        for j in i+1:getBottomRow(A, i)

            try
                f = A[p[j], i] / A[p[i], i]
                A[p[j], i] = 0.0

                for k in i+1:getRightColumn(A, j + A.blockSize)
                    A[p[j], k] -= f * A[p[i], k]
                end

                b[p[j]] -= f * b[p[i]]

            catch DivideError
                println("Zero at the diagonal entry ($i, $i); $(A[i, i])")
            end
        end
    end

    # Back substitution
    x = zeros(n)
    x[n] = b[p[n]] / A[p[n], n]

    for i in n-1:-1:1
        x[i] = b[p[i]]

        for j in i+1:getRightColumn(A, i + A.blockSize)
            x[i] -= A[p[i], j] * x[j]
        end
        
        x[i] /= A[p[i], i]
    end

    return x    
end

"""
    LU_decomposition!(A::SparseMatrix)

Description:
    This function computes the LU decomposition of the matrix A. Optimized for sparse matrices and takes O(n) time. The decomposition will be stored in the matrix A. It returns the permutation vector p.
"""
function LU_decomposition!(A::SparseMatrix, pivot::Bool)::Vector{Int}
    return pivot ? LU_decompositionWithPivot!(A) : LU_decompositionWithoutPivot!(A)
end

function LU_decompositionWithoutPivot!(A::SparseMatrix)

    n = A.size

    for i in 1:n-1
        for j in i+1:getBottomRow(A, i)

            try
                f = A[j, i] / A[i, i]
                A[j, i] = f
                A.LU_size += 1

                for k in i+1:getRightColumn(A, i)
                    A[j, k] -= f * A[i, k]
                    A.LU_size += 1
                end

            catch DivideError
                println("Zero at the diagonal entry ($i, $i); $(A[i, i])")
            end

        end
    end

    return [1:n;]
end

function LU_decompositionWithPivot!(A::SparseMatrix)
    
    n = A.size
    p = [1:n;]

    for i in 1:n-1

        q = reduce((x, y) -> abs(A[p[x], i]) >= abs(A[p[y], i]) ? x : y, i:getBottomRow(A, i))
        p[i], p[q] = p[q], p[i]

        for j in i+1:getBottomRow(A, i)

            try
                f = A[p[j], i] / A[p[i], i]
                A[p[j], i] = f
                A.LU_size += 1

                for k in i+1:getRightColumn(A, i + A.blockSize)
                    A[p[j], k] -= f * A[p[i], k]
                    A.LU_size += 1
                end

            catch DivideError
                println("Zero at the diagonal entry ($i, $i); $(A[i, i])")
            end
        end
    end

    return p
end

"""
    solveUsing_LU!(A::SparseMatrix, b::Vector{Float64}, pivot::Bool)::Vector{Float64}

Description:
    This function solves the system of linear equations using the LU decomposition method. Optimized for sparse matrices and takes O(n) time. Vector b will be modified in the process.

Arguments:
    A::SparseMatrix: Sparse matrix.
    b::Vector{Float64}: Right hand side vector.
    pivot::Bool: If true, the function uses the partial pivoting method.
"""
function solveUsing_LU!(A::SparseMatrix, b::Vector{Float64}, pivot::Bool)::Vector{Float64}
    return pivot ? solveUsing_LU_withPivot(A, b) : solveUsing_LU_withoutPivot(A, b)
end

function solveUsing_LU_withoutPivot(A::SparseMatrix, b::Vector{Float64})::Vector{Float64}
    
    LU_decompositionWithoutPivot!(A)
    n = A.size

    # Forward substitution
    for i in 1:n-1
        for j in i+1:getBottomRow(A, i)
            b[j] -= A[j, i] * b[i]
        end
    end

    # Back substitution
    x = zeros(n)
    for i in n:-1:1
        x[i] = b[i]

        for j in i+1:getRightColumn(A, i)
            x[i] -= A[i, j] * x[j]
        end

        x[i] /= A[i, i]
    end

    return x
end

function solveUsing_LU_withPivot(A::SparseMatrix, b::Vector{Float64})::Vector{Float64}

    p = LU_decompositionWithPivot!(A)
    n = A.size

    # Forward substitution
    for i in 2:n
        for j in getLeftColumn(A, p[i]):i-1
            b[p[i]] -= A[p[i], j] * b[p[j]]
        end
    end

    # Back substitution
    x = zeros(n)
    x[n] = b[p[n]] / A[p[n], n]

    for i in n-1:-1:1
        x[i] = b[p[i]]

        for j in i+1:getRightColumn(A, i + A.blockSize)
            x[i] -= A[p[i], j] * x[j]
        end

        x[i] /= A[p[i], i]
    end

    return x
end


end # module