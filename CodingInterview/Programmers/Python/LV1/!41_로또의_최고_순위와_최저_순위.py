# https://school.programmers.co.kr/learn/courses/30/lessons/77484?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(lottos, win_nums):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]), [3, 5]),
    (([0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]), [1, 6]),
    (([45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35]), [1, 1]),
]

run_tests(solution, test_cases)