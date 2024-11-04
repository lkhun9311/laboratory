input1 = [1, 2, 3, 4, 5, 6, 7, 8]
input2 = [8, 7, 6, 5, 4, 3, 2, 1]
input3 = [8, 1, 7, 2, 6, 3, 5, 4]

def solution1(input):
  if input == sorted(input):
    return "ascending"
  elif input == sorted(input, reverse = True):
    return "descending"
  else:
    return "mixed"

def solution2(input):
  ascending = True
  descending = True

  for index in range(1, len(input)):
    if input[index-1] < input[index]:
      descending = False
    elif input[index-1] > input[index]:
      ascending = False
  
  if ascending:
    return "ascending"
  elif descending:
    return "descending"
  else:
    return "mixed"

print("[solution1]")
print(solution1(input1))
print(solution1(input2))
print(solution1(input3))
print()
print("[solution2]")
print(solution2(input1))
print(solution2(input2))
print(solution2(input3))