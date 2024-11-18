# Piotr Hernik

using JuMP
using GLPK

max_production = [100, 100, 100, 100]
production_cost = [6000, 4000, 8000, 9000]
extrac_production_limit = [60, 65, 70, 60]
extra_production_cost = [8000, 6000, 10000, 11000]
demand = [130, 80, 125, 195]
store_limit = [70, 70, 70, 70]
in_store_on_start = 15
store_cost = [0, 1500, 1500, 1500]

function find_min(max_production::Vector, production_cost::Vector, extrac_production_limit::Vector, extra_production_cost::Vector, demand::Vector, store_limit::Vector, in_store_on_start::Int, store_cost::Vector)

    model = Model(GLPK.Optimizer)

    period = length(production_cost)
    # x - size_of_normal_production
    # y - size_of_extra_production
    # z - in_store
    @variable(model, x[1:period] >= 0)

    @variable(model, y[1:period] >= 0)

    @variable(model, z[1:period] >= 0)

    @constraint(model, x .<= max_production)

    @constraint(model, y .<= extrac_production_limit)

    @constraint(model, z .<= store_limit)

    @constraint(model, z[1] == in_store_on_start)

    @constraint(model, [t in 1:period], x[t] + y[t] + z[t] == demand[t] + (t == period ? 0 : z[t+1]))

    @objective(model, Min, sum(x .* production_cost) + sum(y .* extra_production_cost) + sum(z .* store_cost))

    optimize!(model)
        if termination_status(model) == MOI.OPTIMAL
            println("Wielkość podstawowej produkcji")
            display(value.(x))
            println("Wielkość extra produkcji")
            display(value.(y))
            println("Ilość w magazynie")
            display(value.(z))
            println("Koszt")
            println(objective_value(model))
        elseif termination_status(model) == MOI.INFEASIBLE
            println("The model is infeasible. Check the constraints or data for inconsistencies.")
            return nothing
        else
            println("Solver did not find an optimal solution.")
            return nothing
        end
    end


function find_min(max_production, production_cost, extrac_production_limit, extra_production_cost, demand, store_limit, in_store_on_start, store_cost)