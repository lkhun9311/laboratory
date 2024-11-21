# https://www.acmicpc.net/problem/1543
import time

input1 = ["ababababa", "aba"] # result. 2
input2 = ["a a a a a", "a a"] # result. 2
input3 = ["ababababa", "ababa"] # result. 1
input4 = ["aaaaaaa", "aa"] # result. 3

def solution1(input):
  answer = 0
  source, word = input
  idx = 0
  space = len(word)

  while True:
    if word not in source[idx:]:
      break

    if word == source[idx:idx+space]:
      answer += 1
      idx += space 
    else:
      idx += 1

  return answer

start_time = time.time()
print("[solution1]")
print(solution1(input1))
print(solution1(input2))
print(solution1(input3))
print(solution1(input4))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")

# solution1 코드 최적화
# 핵심. str.find() 내장 함수 활용
def solution2(input):
  answer = 0
  source, word = input
  idx = 0
  space = len(word)

  while True:
    idx = source.find(word, idx)

    if idx == -1:
      break

    answer += 1
    idx += space

  return answer

start_time = time.time()
print("[solution2]")
print(solution2(input1))
print(solution2(input2))
print(solution2(input3))
print(solution2(input4))
end_time = time.time()
print(f"Execution time for solution2: {(end_time - start_time)*1000:.6f} ms")