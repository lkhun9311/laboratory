# https://www.acmicpc.net/problem/5397
import time

input1 = "<<BP<A>>Cd-" # result. BAPC
input2 = "ALK<<P>>>->>EE<<<P>>-" # result. APPLE
input3 = "--A>>B>>>C<<->>>-" # result. B
input4 = "AA--ABCC<<->->E" # result. ACE
input5 = "--ADFG<<<BC>EE-->><<E" # result. ABCDEFG

def solution1(input):
  result = ""
  current_pos = 0
  print("[el | pos | result]")

  for el in input:
    print("$", el, "|", " "+str(current_pos)+" ", "|", result[:current_pos]+"/"+result[current_pos:])
    # el이 [<, >, -]에 속할 경우 수행
    if el in "<>-":
      if current_pos != 0 and el == "<":
        current_pos -= 1
      elif current_pos != len(result) and el == ">":
        current_pos += 1
      elif len(result) != 0 and current_pos != 0 and el == "-":
        result = result[:current_pos-1]+result[current_pos:]
        current_pos -= 1
    # el이 [<, >, -]에 속하지 않을 경우 수행
    else:
      result = result[:current_pos] + el + result[current_pos:]
      current_pos += 1

  return result

start_time = time.time()
print("[solution1]")
print(">", solution1(input1))
print(">")
print(">", solution1(input2))
print(">")
print(">", solution1(input3))
print(">")
print(">", solution1(input4))
print(">")
print(">", solution1(input5))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")

def solution2(input):
  result = ""
  left_stack = []
  right_stack = []

  for el in input:
    if el == "<":
      if left_stack:
        right_stack.append(left_stack.pop())
    elif el == ">":
      if right_stack:
        left_stack.append(right_stack.pop())
    elif el == "-":
      if left_stack:
        left_stack.pop()
    else:
      left_stack.append(el)
  print("left_stack :", left_stack)
  print("right_stack :", right_stack)
  left_stack.extend(reversed(right_stack))
  result = "".join(left_stack)

  return result

start_time = time.time()
print("[solution2]")
print(">", solution2(input1))
print(">")
print(">", solution2(input2))
print(">")
print(">", solution2(input3))
print(">")
print(">", solution2(input4))
print(">")
print(">", solution2(input5))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")