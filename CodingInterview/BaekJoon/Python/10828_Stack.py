# https://www.acmicpc.net/problem/10828
import time

input1 = ["push 1", "push 2", "top", "size", "empty", "pop", "pop", "pop", "size", "empty", "pop", "push 3", "empty", "top"]
input2 = ["pop", "top", "push 123", "top", "pop", "top", "pop"]

def solution1(input):
  result = []
  tmp = []

  for el in input:
    el_arr = el.strip().split(" ")
    el0 = el_arr[0]

    if el0 == "push":
      tmp.append(el_arr[1])
    elif el0 == "pop":
      if len(tmp) == 0:
        result.append("-1")
      else:
        result.append(tmp.pop())
    elif el0 == "size":
      result.append(str(len(tmp)))
    elif el0 == "empty":
      if len(tmp) == 0:
        result.append("1")
      else:
        result.append("0")
    elif el0 == "top":
      if len(tmp) == 0:
        result.append("-1")
      else:
        result.append(tmp[-1])

  return result

start_time = time.time()
print("[solution1]")
print(solution1(input1))
print(solution1(input2))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")