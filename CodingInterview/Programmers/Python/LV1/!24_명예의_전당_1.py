# https://school.programmers.co.kr/learn/courses/30/lessons/138477?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(k, score):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((3, [10, 100, 20, 150, 1, 100, 200]), [10, 10, 10, 20, 20, 100, 100]),
    ((4, [0, 300, 40, 300, 20, 70, 150, 50, 500, 1000]), [0, 0, 0, 0, 20, 40, 70, 70, 150, 300]),
]

run_tests(solution, test_cases)