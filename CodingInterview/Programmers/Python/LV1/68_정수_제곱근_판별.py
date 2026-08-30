# https://school.programmers.co.kr/learn/courses/30/lessons/12934?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

import math


# math.sqrt 는 float 을 주고 float 끼리 비교하면 큰 수에서 거짓 양성이 생긴다.
# (예: sqrt(49999995000000)**2 == 49999995000000 이 참이 되어버림)
# math.isqrt 는 실수를 전혀 거치지 않는 정수 제곱근이라 안전하다.
def is_sqrt_int(n):
    root = math.isqrt(n)
    if root**2 == n:
        return True
    return False


def solution(n):
    if is_sqrt_int(n):
        root = math.isqrt(n)
        return (root+1)**2
    return -1

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (121, 144),
    (3, -1),
    (1, 4),
    (49999995000000, -1),
]

run_tests(solution, test_cases)
