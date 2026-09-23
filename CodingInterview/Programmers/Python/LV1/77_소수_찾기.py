# https://school.programmers.co.kr/learn/courses/30/lessons/12921?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-23

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

import math

def is_prime(number):
    for i in range(2, number):
        if number%i == 0:
            return False
    return True

def solution(n):
    visited = [False for _ in range(n+1)]
    visited[0] = True
    visited[1] = True
    sqrt_number = int(math.sqrt(n))

    for number in range(2, sqrt_number+1):
        if visited[number]:
            continue
        if is_prime(number):
            for i in range(number, n+1):
                if i*number>n:
                    break
                visited[i*number] = True
    return visited.count(False)

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
    (25, 9),                # 25 = 5*5 — sqrt 상한 처리를 확인한다
    (1000000, 78498),       # 제한 최대
]

run_tests(solution, test_cases)
