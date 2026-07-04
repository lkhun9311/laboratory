# https://school.programmers.co.kr/learn/courses/30/lessons/87389?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n):
    for x in range(2, n):
        if n % x == 1:
            return x

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (10, 3),
    (12, 11),
]

run_tests(solution, test_cases)
