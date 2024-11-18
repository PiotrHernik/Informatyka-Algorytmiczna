# Piotr Hernik

using JuMP
using GLPK

cities_amount = 10
starting_city = 1
ending_city = 10
max_time = 15

arches = [[1, 2, 3, 4], [1, 3, 4, 9], [1, 4, 7, 10], [1, 5, 8, 12], [2, 3, 2, 3], [3, 4, 4, 6], [3, 5, 2, 2], [3, 10, 6, 11],
	[4, 5, 1, 1], [4, 7, 3, 5], [5, 6, 5, 6], [5, 7, 3, 3], [5, 10, 5, 8], [6, 1, 5, 8], [6, 7, 2, 2], [6, 10, 7, 11],
	[7, 3, 4, 6], [7, 8, 3, 5], [7, 9, 1, 1], [8, 9, 1, 2], [9, 10, 2, 2]]

arch_exists_matrix = zeros(cities_amount, cities_amount)
arch_costs_matrix = zeros(cities_amount, cities_amount)
arch_times_matrix = zeros(cities_amount, cities_amount)

for arch in arches
	arch_exists_matrix[arch[1], arch[2]] = 1
	arch_costs_matrix[arch[1], arch[2]] = arch[3]
	arch_times_matrix[arch[1], arch[2]] = arch[4]
end

model = Model(GLPK.Optimizer)

@variable(model, 0 <= arch_used[1:cities_amount, 1:cities_amount] <= 1)#, Int)

for i in 1:cities_amount, j in 1:cities_amount
    if arch_exists_matrix[i, j] == 0
        @constraint(model, arch_used[i, j] == 0)
    end
end

@constraint(model, vec(sum(arch_used, dims = 2))[starting_city] == 1)
@constraint(model, vec(sum(arch_used, dims = 1))[ending_city] == 1)

for i in 1:cities_amount
    if i != starting_city && i != ending_city
        @constraint(model, vec(sum(arch_used, dims = 1))[i] == vec(sum(arch_used, dims = 2))[i])
    end
end

# @constraint(model, sum(arch_used .* arch_times_matrix) <= max_time)

@objective(model, Min, sum(arch_used .* arch_costs_matrix))

optimize!(model)

if termination_status(model) == MOI.OPTIMAL
    println("Wybrana droga")
    for i in 1:cities_amount, j in 1:cities_amount
        if value.(arch_used[i, j]) == 1
            println("[$i, $j, $(arch_costs_matrix[i, j]), $(arch_times_matrix[i, j])]")
        end
    end
    display(value.(arch_used))
    println("Koszt")
    println(objective_value(model))
    println("Czas")
    println(sum(value.(arch_used) .* arch_times_matrix))
elseif termination_status(model) == MOI.INFEASIBLE
    println("The model is infeasible. Check the constraints or data for inconsistencies.")
    return nothing
else
    println("Solver did not find an optimal solution.")
    return nothing
end