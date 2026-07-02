
# https://school.programmers.co.kr/learn/courses/30/lessons/42889?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(N, stages):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((5, [2, 1, 2, 6, 2, 4, 3, 3]), [3, 4, 2, 1, 5]),
    ((4, [4, 4, 4, 4, 4]), [4, 1, 2, 3]),
]

run_tests(solution, test_cases)