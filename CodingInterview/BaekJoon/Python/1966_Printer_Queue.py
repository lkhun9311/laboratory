# https://www.acmicpc.net/problem/1966
import time
from collections import deque

target_index1 = 0
weights1 = [5]

target_index2 = 2
weights2 = [1, 2, 3, 4]

target_index3 = 0
weights3 = [1, 1, 9, 1, 1, 1]

def solution1(target_index, weights):
  test_weight = deque([weights[index], index] for index in range(len(weights)))
  # print("test_case :", list(test_weight))
  count = 0

  while target_index in [el[1] for el in test_weight]:
    # print("testing :", list(test_weight))
    first_el = test_weight[0][0]
    first_el_index = test_weight[0][1]

    max_el = max([el[0] for el in test_weight])

    if first_el < max_el:
      test_weight.append(test_weight.popleft())
    elif target_index == first_el_index:
      count += 1
      break
    else:
      test_weight.popleft()
      count += 1

  return count

start_time = time.time()
print("[solution1]")
print(solution1(target_index1, weights1))
print(solution1(target_index2, weights2))
print(solution1(target_index3, weights3))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")

# solution1 코드 최적화 
def solution2(target_index, weights):
  count = 0
  queue = deque(enumerate(weights)) # (핵심!) enumerate() 활용
  
  while queue:
    index, weight = queue.popleft()

    if queue:
      if weight < max(w for i, w in queue): # (핵심!) w 중 max 값 가져오기
        queue.append((index, weight))
      else:
        count += 1
        if index == target_index: # (핵심!) if문을 통해 clean하게 break 
          break
    else:
      count += 1
      break

  return count

start_time = time.time()
print("\n[solution2]")
print(solution2(target_index1, weights1))
print(solution2(target_index2, weights2))
print(solution2(target_index3, weights3))
end_time = time.time()
print(f"Execution time for solution2: {(end_time - start_time)*1000:.6f} ms")

# solution3
def solution3(target_index, weights):
  count = 0
  queue = [(weight, idx) for idx, weight in enumerate(weights)]

  # (핵심!) lambda x: x[0]는 각 tuple의 첫 번째 요소(weight)를 반환하는 간단한 함수
  # (핵심!) max(queue, key = lambda x: x[0]): queue의 각 tuple 중 weight이 가장 큰 tuple((max_weight, idx))을 반환
  # (핵심!) max(queue, key = lambda x: x[0])[0]: max tuple의 첫 번째 요소(weight)를 반환 
  while True:
    if queue[0][0] == max(queue, key = lambda x: x[0])[0]: 
      count += 1
      if queue[0][1] == target_index:
        break
      else:
        queue.pop(0)
    else:
      queue.append(queue.pop(0))

  return count

start_time = time.time()
print("\n[solution3]")
print(solution3(target_index1, weights1))
print(solution3(target_index2, weights2))
print(solution3(target_index3, weights3))
end_time = time.time()
print(f"Execution time for solution3: {(end_time - start_time)*1000:.6f} ms")