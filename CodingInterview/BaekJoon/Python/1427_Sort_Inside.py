# https://www.acmicpc.net/problem/1427
import time

input1 = 2143 # result. 4321
input2 = 999998999 # result. 999999998
input3 = 61423 # result. 64321
input4 = 500613009 # result. 965310000

def solution1(input):
  tmp = list(str(input))
  tmp.sort(reverse = True)
  result = "".join(tmp)

  return result

start_time = time.time()
print("[solution1]")
print(solution1(input1))
print(solution1(input2))
print(solution1(input3))
print(solution1(input4))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")