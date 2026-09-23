# https://school.programmers.co.kr/learn/courses/30/lessons/12921?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-23

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

import math

def is_prime(number):
    sqrt_number = int(math.sqrt(number))+1
    for i in range(2, sqrt_number):
        if number%i == 0:
            return False
    return True

def solution(n):
    answer = 0
    for number in range(2, n+1):
        if is_prime(number):
            answer += 1
    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (10, 4),
    (5, 3),

    # 아래는 직접 추가한 경계 케이스
    (2, 1),                 # 최소 입력
    (3, 2),
    (4, 2),                 # 4 = 2*2 는 소수가 아니다
    (25, 9),                # 25 = 5*5 — sqrt 상한에 +1 이 없으면 여기서 틀린다
    (1000000, 78498),       # 제한 최대. 이 방식은 여기서 약 1 초 걸린다 (체 방식은 0.02 초)
]

run_tests(solution, test_cases)
