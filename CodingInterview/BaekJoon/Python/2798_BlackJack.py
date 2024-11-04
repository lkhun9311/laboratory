# https://www.acmicpc.net/problem/2798
input1 = [5, 6, 7, 8, 9]
max_value1 = 21

input2 = [93, 181, 245, 214, 315, 36, 185, 138, 216, 295]
max_value2 = 500

def solution1(input, max_value):
  arr = []
  
  for i in range(len(input)-2):
    for j in range(i+1, len(input)-1):
      for k in range(j+1, len(input)):
        element = input[i] + input[j] + input[k]
        if element > max_value:
          continue
        arr.append(element)
        
  arr.sort(reverse=True)
  return arr[0]

def solution2(input, max_value):
  result = 0
  
  for i in range(len(input)-2):
    for j in range(i+1, len(input)-1):
      for k in range(j+1, len(input)):
        element = input[i] + input[j] + input[k]
        if element > max_value:
          continue
        result = max(result, element)

  return result

print("[solution1]")
print(solution1(input1, max_value1))
print(solution1(input2, max_value2))
print()
print("[solution2]")
print(solution2(input1, max_value1))
print(solution2(input2, max_value2))