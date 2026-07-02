# https://school.programmers.co.kr/learn/courses/30/lessons/64061?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(board, moves):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([[0, 0, 0, 0, 0],
       [0, 0, 1, 0, 3],
       [0, 2, 5, 0, 1],
       [4, 2, 4, 4, 2],
       [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4]), 4),
]

run_tests(solution, test_cases)