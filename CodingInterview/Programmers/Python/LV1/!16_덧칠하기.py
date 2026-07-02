# https://school.programmers.co.kr/learn/courses/30/lessons/161989?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n, m, section):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((8, 4, [2, 3, 6]), 2),
    ((5, 4, [1, 3]), 1),
    ((4, 1, [1, 2, 3, 4]), 4),
]

run_tests(solution, test_cases)