# https://www.acmicpc.net/problem/10930
import time
import hashlib

input1 = "Baekjoon" # result. 9944e1862efbb2a4e2486392dc6701896416b251eccdecb8332deb7f4cf2a857

# 1. 문자열 input을 byte로 encoding 후 SHA-256 Hash 객체 생성 (hashlib.sha256())
# 2. SHA-256 Hash 객체를 16진수 문자열로 출력 (hexdigest())
def solution1(input):
  # 문자열 input을 byte로 encoding 후 SHA-256 Hash 객체 생성
  input_sha_256_hashed = hashlib.sha256(input.encode())

  # SHA-256 Hash 객체를 16진수 문자열로 출력
  result = input_sha_256_hashed.hexdigest()
  return result

start_time = time.time()
print("[solution1]")
print(solution1(input1))
end_time = time.time()
print(f"Execution time for solution1: {(end_time - start_time)*1000:.6f} ms")

# 가독성 고려
def solution2(input):
  input_encoded = input.encode()
  result = hashlib.sha256(input_encoded).hexdigest()
  return result

start_time = time.time()
print("[solution2]")
print(solution2(input1))
end_time = time.time()
print(f"Execution time for solution2: {(end_time - start_time)*1000:.6f} ms")