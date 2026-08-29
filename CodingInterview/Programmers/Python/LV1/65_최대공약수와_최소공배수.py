# https://school.programmers.co.kr/learn/courses/30/lessons/12940?language=python3

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

import math


def solution(n, m):
    # 규칙. [최대공약수, 최소공배수] 를 돌려준다.
    #      math.lcm 은 Python 3.9+ 이므로, 채점 환경이 낮으면
    #      gcd 만 쓰고 n * m // gcd 로 계산해도 된다 (파이썬 정수는 크기 제한이 없다).
    return [math.gcd(n, m), math.lcm(n, m)]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((3, 12), [3, 12]),
    ((2, 5), [1, 10]),
    ((1, 1), [1, 1]),
    ((1000000, 1000000), [1000000, 1000000]),
    ((999983, 999979), [1, 999962000357]),
]

run_tests(solution, test_cases)
