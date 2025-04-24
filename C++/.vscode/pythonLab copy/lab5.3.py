import numpy as np

# Define the PMF for the given distribution
pmf = {1: 0.3, 2: 0.4, 3: 0.2, 4: 0.1}

# Calculate the CDF
cdf = {}
cumulative_probability = 0

for x in sorted(pmf.keys()):
    cumulative_probability += pmf[x]
    cdf[x] = cumulative_probability

# Function to generate a single random number based on the CDF
def generate_random_number(cdf):
    u = np.random.uniform()  # Generate a random number from [0, 1)
    for x in cdf:
        if u <= cdf[x]:
            return x
    return x  # In case of rounding issues, return the last value

# Generate 2000 random numbers
random_numbers = [generate_random_number(cdf) for i in range(2000)]

# Print the first 10 random numbers as a sample
print("Sample of 10 random numbers:")
print(random_numbers[:10])