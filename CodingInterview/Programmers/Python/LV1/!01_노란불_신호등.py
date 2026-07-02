# https://school.programmers.co.kr/learn/courses/30/lessons/468371?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(signals):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([[2, 1, 2], [5, 1, 1]], 13),
    ([[2, 3, 2], [3, 1, 3], [2, 1, 1]], 11),
    ([[3, 3, 3], [5, 4, 2], [2, 1, 2]], 193),
    ([[1, 1, 4], [2, 1, 3], [3, 1, 2], [4, 1, 1]], -1),
]

run_tests(solution, test_cases)