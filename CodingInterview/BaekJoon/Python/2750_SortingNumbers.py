# https://www.acmicpc.net/problem/2750
import time

input1 = [5, 5, 2, 3, 4, 1] # result. [1, 2, 3, 4, 5]

def solution1(input):
  result = []

  for el in input:
    if el in result:
      continue
    
    result.append(el)

  result.sort(reverse = False)

  return result

start_time = time.time()
print("[solution1]")
print(solution1(input1))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")