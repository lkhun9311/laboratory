# https://www.acmicpc.net/problem/10773
import time

input1 = [3, 0, 4, 0] # result. 0
input2  = [1, 3, 5, 4, 0, 0, 7, 0, 0, 6] # result. 7

def solution1(input):
  tmp = []

  for el in input:
    if el == 0:
      tmp.pop()
    else:
      tmp.append(el)

  return sum(tmp)

start_time = time.time()
print("[solution1]")
print(solution1(input1))
print(solution1(input2))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")