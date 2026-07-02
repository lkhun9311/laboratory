# https://school.programmers.co.kr/learn/courses/30/lessons/135808?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(k, m, score):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((3, 4, [1, 2, 3, 1, 2, 3, 1]), 8),
    ((4, 3, [4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2]), 33),
]

run_tests(solution, test_cases)