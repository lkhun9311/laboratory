# https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(answers):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([1, 2, 3, 4, 5], [1]),
    ([1, 3, 2, 4, 2], [1, 2, 3]),
]

run_tests(solution, test_cases)