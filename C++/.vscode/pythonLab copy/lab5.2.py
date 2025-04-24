correct_answers = {0,1,2,3,4,5}
frequency = {5,7,10,20,12,6}

total_students = sum(frequency)

probablities = [f/total_students for f in frequency]

#mean = sum(correct answers * probabilities)
mean = sum(x * p for x, p in zip(correct_answers,probablities))

#vairance = sum((x-mean)^2 * probability)
variance = sum((x-mean) ** 2 * p for x, p in zip(correct_answers, probablities))

prob_4 = sum(probablities[4:])

print(f"Mean of X : {mean:.2f}")
print(f"Variance of X : {variance:.2f}")
print(f"probablity of atleast 4 correct : {prob_4:.2f}")