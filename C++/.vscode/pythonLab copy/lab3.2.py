import numpy as np
from scipy.stats import binom

def compute_probabilities(n):

    #probability of each success
    p = 0.5
    
    #possible outcomes
    x_values = np.arange(0, n + 1)
    
    #probablity mass function
    #probability of x success in n trails where p is the probabiliy of each success
    probabilities = binom.pmf(x_values, n, p)
    
    print(f"Probabilities for {n} coin tosses:")
    for x, prob in zip(x_values, probabilities):
        print(f"P(X = {x}) = {prob:.2f}")

compute_probabilities(4)
