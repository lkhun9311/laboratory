# https://school.programmers.co.kr/learn/courses/30/lessons/134240?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(food):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([1, 3, 4, 6], "1223330333221"),
    ([1, 7, 1, 2], "111303111"),
]

run_tests(solution, test_cases)