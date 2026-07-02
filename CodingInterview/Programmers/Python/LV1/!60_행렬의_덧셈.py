# https://school.programmers.co.kr/learn/courses/30/lessons/12950?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(arr1, arr2):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([[1, 2], [2, 3]], [[3, 4], [5, 6]]), [[4, 6], [7, 9]]),
    (([[1], [2]], [[3], [4]]), [[4], [6]]),
]

run_tests(solution, test_cases)