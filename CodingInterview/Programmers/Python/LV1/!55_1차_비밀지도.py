# https://school.programmers.co.kr/learn/courses/30/lessons/17681?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n, arr1, arr2):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]),
     ["#####", "# # #", "### #", "#  ##", "#####"]),
    ((6, [46, 33, 33, 22, 31, 50], [27, 56, 19, 14, 14, 10]),
     ["######", "###  #", "##  ##", " #### ", " #####", "### # "]),
]

run_tests(solution, test_cases)