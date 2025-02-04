# Piotr Hernik

include("sparseModule/src/sparseModule.jl")
include("blocksys/src//blocksys.jl")
include("matrixgen.jl")

using .sparseModule
using .blocksys
using .matrixgen
using FilePathsBase
using Printf



SIZE = 500000
BLOCK_SIZE = 4


function challenge(A, b, IS_PIVOT, outputFile)
    p = solveUsingSparseLU!(A, b, IS_PIVOT)
    err = sparseModule.calculateError(p)
    println(err)
    sparseModule.writeSolutionToFile(outputFile, p, err)

end

function benchmark()

    blockmat(SIZE, BLOCK_SIZE, 1.0, "A.txt")
    A = sparseModule.readMatrixFromFile("A.txt")
    b = sparseModule.calculateRightHandSideVector(A)
    p = solveUsingSparseLU!(A, b, false)
    err = sparseModule.calculateError(p)
    sparseModule.writeSolutionToFile("LUwithoutPivot", p, err)

    blockmat(SIZE, BLOCK_SIZE, 1.0, "A.txt")
    A = sparseModule.readMatrixFromFile("A.txt")
    b = sparseModule.calculateRightHandSideVector(A)
    p = solveUsingSparseLU!(A, b, true)
    err = sparseModule.calculateError(p)
    sparseModule.writeSolutionToFile("LUwithPivot", p, err)

    blockmat(SIZE, BLOCK_SIZE, 1.0, "A.txt")
    A = sparseModule.readMatrixFromFile("A.txt")
    b = sparseModule.calculateRightHandSideVector(A)
    p = sparseGaussianSolve!(A, b, false)
    err = sparseModule.calculateError(p)
    sparseModule.writeSolutionToFile("GaussWithoutPivot", p, err)

    blockmat(SIZE, BLOCK_SIZE, 1.0, "A.txt")
    A = sparseModule.readMatrixFromFile("A.txt")
    b = sparseModule.calculateRightHandSideVector(A)
    p = sparseGaussianSolve!(A, b, true)
    err = sparseModule.calculateError(p)
    sparseModule.writeSolutionToFile("GaussWithPivot", p, err)

end

benchmark()