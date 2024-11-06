# https://www.acmicpc.net/problem/1874
from collections import deque
import time

input1 = 8
arr1 = [4, 3, 6, 8, 7, 5, 2, 1]

input2 = 5
arr2 = [1, 2, 5, 3, 4]

def solution1(input, arr):
  # arr의 max element 이후의 요소를 reverse해서 reverse_arr_after_max_element 정의
  # (예정) arr의 max element를 점검한 이후의 stack_arr와 reverse_arr_after_max_element가 같은지 비교
  index_of_max_element_of_arr = arr.index(input)
  arr_after_max_element = arr[index_of_max_element_of_arr:]
  reverse_arr_after_max_element = arr_after_max_element[-1::-1]

  origin_arr = deque([i+1 for i in range(input)])
  stack_arr = deque()
  result = []

  for el in arr:
    # print("result :", result)
    # print("stack_arr :", stack_arr) 

    if el == input:
      # print("origin_arr :", origin_arr)
      stack_arr.extend(origin_arr)
      for i in range(len(origin_arr)):
        result.append("+")
      # print("result :", result)
      # print("stack_arr :", stack_arr) 
      break

    while origin_arr[0] <= el:
      value = origin_arr.popleft()
      stack_arr.append(value)
      result.append("+")
    
    if stack_arr[-1] == el:
      stack_arr.pop()
      result.append("-")

  # print("reverse_arr_after_max_element :", reverse_arr_after_max_element)
  # print("list(stack_arr) :", list(stack_arr))
    
  if list(stack_arr) == reverse_arr_after_max_element:
    length_of_stack_arr = len(stack_arr)
    result.extend(length_of_stack_arr * "-")
    return result
  else:
    return "NO"

start_time = time.time()
print("[solution1]")
print(solution1(input1, arr1))
print(solution1(input2, arr2))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")

# solution1 코드 최적화 
def solution2(input_size, target_sequence):
    origin_stack = deque(range(1, input_size + 1))  # 원본 배열을 1부터 input_size까지 생성
    stack = deque()  # 스택 시뮬레이션을 위한 deque
    result = []  # 연산 기록을 저장할 리스트
    current_index = 0  # target_sequence의 현재 위치를 추적

    for number in target_sequence:
        # (핵심!) 스택이 비어있거나 스택의 최상단 값이 현재 필요한 값보다 작은 경우, 숫자를 스택에 추가
        while origin_stack and (not stack or stack[-1] < number):
            stack.append(origin_stack.popleft())
            result.append("+")
        
        # 스택의 최상단 값이 필요한 값과 일치하는 경우, 스택에서 팝
        if stack[-1] == number:
            stack.pop()
            result.append("-")
        else:
            # (핵심!) 스택의 최상단 값이 필요한 값과 일치하지 않을 경우, 불가능한 시퀀스임
            return "NO"

    return result

print()
start_time = time.time()
print("\n[solution2]")
print(solution2(input1, arr1))
print(solution2(input2, arr2))
end_time = time.time()
print(f"Execution time for solution2: {(end_time - start_time)*1000:.6f} ms")