# Piotr Hernik

module sparseModule

using Printf
using FilePathsBase
using LinearAlgebra

export MySparseMatrix, readMatrixFromFile, getNonZeroRowsBelow, getNonZeroRowsUp, getNonZeroColumnsLeft, getNonZeroColumnsRight, printSystem

mutable struct MySparseMatrix
    data::Dict{Tuple{Int, Int}, Float64}
    size::Int
    numberOfBlocks::Int
    blockSize::Int
    numberOfNonZero::Int
    numberOfReferences::Int
    LU_size::Int

    function MySparseMatrix(data::Dict{Tuple{Int, Int}, Float64}, n::Int, v::Int, l::Int, numberOfNonZero::Int)
        new(data, n, v, l, numberOfNonZero, 0, 0)
    end
end

function Base.getindex(A::MySparseMatrix, i::Int, j::Int)
    A.numberOfReferences += 1
    get(A.data, (i, j), 0.0)
end

function Base.setindex!(A::MySparseMatrix, val::Number, i::Int, j::Int)
    A.numberOfReferences += 1
    A.data[(i, j)] = Float64(val)
end

function Base.show(io::IO, A::MySparseMatrix)
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


#     readMatrixFromFile(filename::String)::MySparseMatrix
# Description:
#     This function reads a matrix from a file and returns a MySparseMatrix object.

function readMatrixFromFile(filename::String)::MySparseMatrix
    A, n, l, nonZero = open(filename, "r") do file
        counter = 0
        line = readline(file)
        n, l = parse.(Int, split(line))

        data = Dict{Tuple{Int, Int}, Float64}()
        for line in eachline(file)
            isempty(line) && continue
            i, j, value = split(line)
            data[(parse(Int, i), parse(Int, j))] = parse(Float64, value)
            counter += 1
        end
        data, n, l, counter
    end

    return MySparseMatrix(A, n, div(n, l), l, nonZero)
end


#     readVectorFromFile(filename::String)::Vector{Float64}
# Description:
#     This function reads right side vector from filename and returns it.

# Arguments:
#     filename::String: Path to the file with the vector.

# Returns:
#     Vector{Float64}: Vector.

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



#     getNonZeroRowsBelow(A::MySparseMatrix, k::Int)::Int

# Description:
#     This function finds the nonzero rows below the given column index `k`.

function getNonZeroRowsBelow(A::MySparseMatrix, k::Int)::Int
    return min(A.size, A.blockSize * (1 + floor(Int, (k + 1) / A.blockSize)))
end


#     getNonZeroRowsUp(A::MySparseMatrix, k::Int)::Int

# Description:
#     This function finds the nonzero rows above the given column index `k`.

function getNonZeroRowsUp(A::MySparseMatrix, k::Int)::Int
    return max(1, k - A.blockSize)
end


#     getNonZeroColumnsLeft(A::MySparseMatrix, r::Int)::Int

# Description:
#     This function finds the nonzero columns to the left of the given row index `r`.

function getNonZeroColumnsLeft(A::MySparseMatrix, r::Int)::Int
    return max(1, A.blockSize * floor(Int, (r - 1) / A.blockSize) - 1)
end


#     getNonZeroColumnsRight(A::MySparseMatrix, r::Int)::Int

# Description:
#     This function finds the nonzero columns to the right of the given row index `r`.

function getNonZeroColumnsRight(A::MySparseMatrix, r::Int)::Int
    return min(A.blockSize + r, A.size)
end


#     calculateRightHandSideVector(A::MySparseMatrix, x::Union{Vector{Float64}, Nothing} = nothing)::Vector{Float64}

# Description:
#     This function calculates the right-hand side vector of the system Ax = b.

function calculateRightHandSideVector(A::MySparseMatrix, x::Union{Vector{Float64}, Nothing} = nothing)::Vector{Float64}
    n = A.size

    if x === nothing
        x = ones(n)
    end

    y = zeros(n)

    for i in 1:n
        for j in getNonZeroColumnsLeft(A, i):getNonZeroColumnsRight(A, i)
            y[i] += A[i, j] * x[j]
        end
    end
    return y
end

#     calculateError(x::Vector{Float64}, solution::Union{Vector{Float64}, Nothing} = nothing)::Float64

# Description:
#     This function calculates the error of the solution x with respect to the solution vector

# Arguments:
#     x::Vector{Float64}: Solution vector.
#     solution::Vector{Float64}: Solution vector, default value of is [1, 1, ..., 1]

function calculateError(x::Vector{Float64}, solution::Union{Vector{Float64}, Nothing} = nothing)::Float64
    if solution === nothing
        solution = ones(length(x))
    end
    return norm(x - solution) / norm(solution)
end



#     writeSolutionToFile(filename::String, x::Vector{Float64}, error::Float64 = NaN)

# Description:
#     This function writes the solution vector x to the file filename.

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

function getDictSize(matrix::MySparseMatrix)
    total_size = 0
    
    total_size += sizeof(matrix.data)
    
    for (key, value) in matrix.data
        total_size += sizeof(key) + sizeof(value)
    end
    
    return total_size
end

end # module

