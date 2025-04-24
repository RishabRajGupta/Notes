import random

#number of trails
n_simulations = 1000

#dictionary to store how many times each possible sum of the dice appears
sum_frequencies = {i: 0 for i in range (4,33)}

#updates dictionary for every 4 trials
for x in range(n_simulations):
    n = sum(random.randint(1,8) for i in range(4))
    sum_frequencies[n] += 1


for z in sum_frequencies:
    sum_frequencies[z] /= n_simulations

for z in range(4,33):
    print(f"Z = {z}, P(Z = {z}) = {sum_frequencies[z]}")
    print("%.10f" %sum_frequencies[z])