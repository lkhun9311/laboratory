# https://school.programmers.co.kr/learn/courses/30/lessons/340198?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(mats, park):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([5, 3, 2], [["A", "A", "-1", "B", "B", "B", "B", "-1"],
                   ["A", "A", "-1", "B", "B", "B", "B", "-1"],
                   ["-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"],
                   ["D", "D", "-1", "-1", "-1", "-1", "E", "-1"],
                   ["D", "D", "-1", "-1", "-1", "-1", "-1", "F"],
                   ["D", "D", "-1", "-1", "-1", "-1", "E", "-1"]]), 3),
]

run_tests(solution, test_cases)