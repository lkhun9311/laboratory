# https://school.programmers.co.kr/learn/courses/30/lessons/250125?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(board, h, w):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([["blue", "red", "orange", "red"], ["red", "red", "blue", "orange"], ["blue", "orange", "red", "red"], ["orange", "orange", "red", "blue"]], 1, 1), 2),
    (([["yellow", "green", "blue"], ["blue", "green", "yellow"], ["yellow", "blue", "blue"]], 0, 1), 1),
]

run_tests(solution, test_cases)