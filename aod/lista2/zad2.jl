#Piotr Hernik

using JuMP
using GLPK

time_on_machine = [5/60 10/60 6/60; 3/60 6/60 4/60; 4/60 5/60 3/60; 4/60 2/60 1/60]
amount_of_product, amount_of_machine = size(time_on_machine)
price_for_kg = [9, 7, 6, 5]
machine_cost = [2, 2, 3]
material_cost = [4, 1, 1, 1]
max_demand = [400, 100, 150, 500]
availibility = [60, 60, 60]

function find_max(time_on_machine::Matrix, price_for_kg::Vector, machine_cost::Vector, material_cost::Vector, max_demand::Vector, availibility::Vector)

    model = Model(GLPK.Optimizer)

    @variable(model, x[1:amount_of_product] >= 0)

    @constraint(model,  sum(repeat(x, 1, amount_of_machine)  .* time_on_machine, dims = 1) .<= availibility)

    @constraint(model, x .<= max_demand)

    @objective(model, Max, sum((price_for_kg .- material_cost) .* x) - sum(machine_cost .* sum(repeat(x, 1, amount_of_machine) .* time_on_machine, dims = 1)))


    optimize!(model)
    if termination_status(model) == MOI.OPTIMAL
        println("Ilość produktu w kilogramach")
        display(value.(x))
        println("Profit")
        println(objective_value(model))
    elseif termination_status(model) == MOI.INFEASIBLE
		println("The model is infeasible. Check the constraints or data for inconsistencies.")
		return nothing
	else
		println("Solver did not find an optimal solution.")
		return nothing
	end

end

find_max(time_on_machine, price_for_kg, machine_cost, material_cost, max_demand, availibility)