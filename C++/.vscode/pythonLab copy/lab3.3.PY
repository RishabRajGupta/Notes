k = int(input("Enter the value of k : "))
n = int(input("Enter the value of n : "))

result_list = []
for i in range(1, n + 1):
    number = int(str(k) * i)
    result_list.append(number)

total_sum = sum(result_list)

result_string = '+'.join(str(num) for num in result_list)

print(f"The result of adding {k} in the specified pattern is: {result_string} = {total_sum}")
