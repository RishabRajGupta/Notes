import matplotlib.pyplot as plt

outcomes = [1, 2, 3, 4, 5, 6]

pmf = [1/6,1/6,1/6,1/6,1/6,1/6] 

plt.bar(outcomes, pmf, width= 0.6, color='blue')
plt.xlabel('Outcome of Die Roll')
plt.ylabel('Probability')
plt.title('PMF of Rolling a Fair Six-Sided Die')
plt.show()