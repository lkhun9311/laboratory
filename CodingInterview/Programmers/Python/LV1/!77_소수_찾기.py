# https://school.programmers.co.kr/learn/courses/30/lessons/12921?language=python3

# Number of times solving questions: 1
# 2026-06-21

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution1(n):
    result = 0

    for i in range(2, n+1):
        if is_prime(i):
            result += 1

    return result

def is_prime(num):
    for i in range(2, int(num**(0.5))+1):
        if num % i == 0:
            return False
    return True

def solution2(n):
    result = 0

    return result

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (10, 4),
    (5, 3),
]

run_tests([solution1, solution2], test_cases)