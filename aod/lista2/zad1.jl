#Piotr Hernik

using JuMP
using GLPK

function find_min(cost::Matrix, supliers::Vector, demands::Vector)

    m, n = size(cost)

    model = Model(GLPK.Optimizer)

    @variable(model, x[1:m, 1:n]>= 0)

    @constraint(model, [d in 1:m], sum(x[d, :]) == demands[d])

    @constraint(model, [s in 1:n], sum(x[:, s]) <= supliers[s])

    @objective(model, Min, sum(x[i, j] * cost[i, j] for i in 1:m, j in 1:n))

    optimize!(model)

    if termination_status(model) == MOI.OPTIMAL
		println("Wysyłane paliwo")
        display(value.(x))
        println("Koszt")
        @show objective_value(model)
    elseif termination_status(model) == MOI.INFEASIBLE
		println("The model is infeasible. Check the constraints or data for inconsistencies.")
		return nothing
	else
		println("Solver did not find an optimal solution.")
		return nothing
	end
end

cost = [10 7 8; 10 11 14; 9 12 4; 11 13 9]
supliers = [275000, 550000, 660000]
demands = [110000, 220000, 330000, 440000]

find_min(cost, supliers, demands)