import random
import math

#mean
def calculate_mean(data):
    return sum(data) / len(data)

#variance = sum(x-mean)^2/no of elements
def calculate_variance(data):
    mean = calculate_mean(data)
    return sum((x - mean) ** 2 for x in data) / len(data)

#standard deviation
def calculate_dev(data):
    variance = calculate_variance(data)
    return math.sqrt(variance)

#covariance = deviation(x) * deviation(y) / no of elements(x)
def calculate_covariance(dataset1, dataset2):
    mean1 = calculate_mean(dataset1)
    mean2 = calculate_mean(dataset2)
    
    covariance = sum((x - mean1) * (y - mean2) for x, y in zip(dataset1, dataset2)) / len(dataset1)
    return covariance

#pearson coeff = covar(x,y)/standard dev(x) *standard dev(y)
def calculate_pearson_corr(dataset1, dataset2):
    stddev1 = calculate_dev(dataset1)
    stddev2 = calculate_dev(dataset2)
    
    covariance = calculate_covariance(dataset1, dataset2)
    
    return covariance / (stddev1 * stddev2)

dataset1 = [random.uniform(0, 50) for i in range(1000)]
dataset2 = [random.uniform(0, 50) for i in range(1000)]

pearson_corr = calculate_pearson_corr(dataset1, dataset2)

print(f"Pearson Correlation Coefficient: {pearson_corr}")