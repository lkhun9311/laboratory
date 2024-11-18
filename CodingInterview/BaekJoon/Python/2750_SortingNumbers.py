# https://www.acmicpc.net/problem/2750
import time

input1 = [5, 2, 3, 4, 1] # result. [1, 2, 3, 4, 5]

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

# solution1 최적화 
def solution2(input):
  return sorted(input)

start_time = time.time()
print("\n[solution2]")
print(solution2(input1))
end_time = time.time()
print(f"Execution time for solution2: {(end_time - start_time)*1000:.6f} ms")

def solution3(input):
  result = input

  for idx in range(len(input)):
    min_index = idx
    for j in range(idx+1, len(input)):
      if result[min_index] > result[j]:
        min_index = j
    # 핵심. Swap 활용     
    result[idx], result[min_index] = result[min_index], result[idx]

  return result

start_time = time.time()
print("\n[solution3]")
print(solution3(input1))
end_time = time.time()
print(f"Execution time for solution3: {(end_time - start_time)*1000:.6f} ms")