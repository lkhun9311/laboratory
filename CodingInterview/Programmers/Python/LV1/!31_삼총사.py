# https://school.programmers.co.kr/learn/courses/30/lessons/131705?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(number):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([-2, 3, 0, 2, -5], 2),
    ([-3, -2, -1, 0, 1, 2, 3], 5),
    ([-1, 1, -1, 1], 0),
]

run_tests(solution, test_cases)