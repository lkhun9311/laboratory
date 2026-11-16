# https://school.programmers.co.kr/learn/courses/30/lessons/340198?language=python3

# Number of times solving questions: 1
# 2026-11-16

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(mats, park):
    r = len(park)
    c = len(park[0])

    for mat in sorted(mats, reverse=True):
        for i in range(r - mat + 1):
            for j in range(c - mat + 1):
                is_empty = True

                for x in range(i, i+mat):
                    for y in range(j, j+mat):
                        if park[x][y] != "-1":
                            is_empty = False
                            break
                    if not is_empty:
                        break
                if is_empty:
                    return mat
    return -1

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