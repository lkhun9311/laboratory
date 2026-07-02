# https://school.programmers.co.kr/learn/courses/30/lessons/250137?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(bandage, health, attacks):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([5, 1, 5], 30, [[2, 10], [9, 15], [10, 5], [11, 5]]), 5),
    (([3, 2, 7], 20, [[1, 15], [5, 16], [8, 6]]), -1),
    (([4, 2, 7], 20, [[1, 15], [5, 16], [8, 6]]), -1),
    (([1, 1, 1], 5, [[1, 2], [3, 2]]), 3),
]

run_tests(solution, test_cases)