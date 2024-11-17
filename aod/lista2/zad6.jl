# Piotr Hernik

using JuMP
using GLPK

kontenery_matrix = [
    1 0 1 0 0;
    0 0 1 1 0;
    1 0 1 0 1;
    0 0 0 1 1;
    0 1 0 1 0;
]

camera_range = 2

function solve(kontenery_matrix::Matrix, camera_range::Int)

    model = Model(GLPK.Optimizer)

    m, n = size(kontenery_matrix)

    @variable(model, 0 <= x[1:m, 1:n] <= 1, Int)

    for i in 1:m, j in 1:n
        if(kontenery_matrix[i, j] == 1)
            @constraint(model, sum(x[i, j]) == 0)
            @constraint(model, sum(x[i, max(1, j - camera_range):min(j + camera_range,n)]) + sum(x[max(1, i - camera_range):min(i + camera_range, m), j]) >= 1)
        end
    end

    @objective(model, Min, sum(x))


    optimize!(model)

    if termination_status(model) == MOI.OPTIMAL
        println("Rozmieszczenie kamer")
        display(kontenery_matrix -= value.(x))
        println("Liczba kamer")
        println(objective_value(model))
    elseif termination_status(model) == MOI.INFEASIBLE
        println("The model is infeasible. Check the constraints or data for inconsistencies.")
        return nothing
    else
        println("Solver did not find an optimal solution.")
        return nothing
    end
end

solve(kontenery_matrix, camera_range)
