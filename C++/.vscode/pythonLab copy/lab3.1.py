import numpy as np
from collections import Counter

word_list = np.array(["I", "am", "Studying", "in", "BU"])

random_words = np.random.choice(word_list, 1500)

bu_indices = np.where(random_words == "BU")[0]

neighbors_of_BU = random_words[bu_indices + 1]

sample_space_count = Counter(neighbors_of_BU)

total_count = len(neighbors_of_BU)

#dictionary
probabilities = {word: count / total_count for word, count in sample_space_count.items()}

print("Sample Space for 'BU':", neighbors_of_BU)
print("Probability Distribution:")
for word, prob in probabilities.items():
    print(f"{word}: {prob:.4f}")
