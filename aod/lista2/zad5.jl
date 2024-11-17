#Piotr Hernik

using JuMP
using GLPK

min_zmiany = [10, 20, 18]
min_dzielnicy = [10, 14, 13]
min_radiowozow_matrix = [2 4 3; 3 6 5; 5 7 6]
max_radiowozow_matrix = [3 7 5; 5 7 10; 8 12 10]

function solve(min_radiowozow_matrix::Matrix, max_radiowozow_matrix::Matrix, min_zmiany::Vector, min_dzielnicy::Vector)

    m, n = size(min_radiowozow_matrix)

    model = Model(GLPK.Optimizer)

    @variable(model, x[1:m, 1:n] >= 0, Int)

    @constraint(model, x .>= min_radiowozow_matrix)
    @constraint(model, x .<= max_radiowozow_matrix)
    @constraint(model, vec(sum(x, dims=1)) .>= min_zmiany)
    @constraint(model, vec(sum(x, dims=2)) .>= min_dzielnicy)

    @objective(model, Min, sum(x))

    optimize!(model)

    if termination_status(model) == MOI.OPTIMAL
		println("Rozmieszczenie radiowozów")
		display(value.(x))
		println("Liczba radiowozów")
		println(objective_value(model))
	elseif termination_status(model) == MOI.INFEASIBLE
		println("The model is infeasible. Check the constraints or data for inconsistencies.")
		return nothing
	else
		println("Solver did not find an optimal solution.")
		return nothing
	end
end

solve(min_radiowozow_matrix, max_radiowozow_matrix, min_zmiany, min_dzielnicy)