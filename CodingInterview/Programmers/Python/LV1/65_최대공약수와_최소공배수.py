# https://school.programmers.co.kr/learn/courses/30/lessons/12940?language=python3

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

import math


def solution(n, m):
    # 규칙. [최대공약수, 최소공배수] 를 돌려준다.
    #      lcm = n * m // gcd 인데, 나눗셈을 먼저 해서 중간값을 줄인다.
    #      파이썬은 정수 크기 제한이 없어 필수는 아니지만 C++ 버전과 식을 맞춰 둔다.
    #      (math.lcm 은 Python 3.9+ 라 채점 환경에 따라 못 쓸 수 있다)
    gcd = math.gcd(n, m)

    return [gcd, (n//gcd)*m]

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
