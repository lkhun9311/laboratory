# https://school.programmers.co.kr/learn/courses/30/lessons/12944?language=python3

# Number of times solving questions: 1
# 2026-08-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(arr):
    arr_size = len(arr)
    arr_sum = sum(arr)
    return arr_sum / arr_size

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([1, 2, 3, 4], 2.5),
    ([5, 5], 5.0),
]

run_tests(solution, test_cases)