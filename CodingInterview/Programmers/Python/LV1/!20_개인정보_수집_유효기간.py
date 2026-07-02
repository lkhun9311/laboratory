# https://school.programmers.co.kr/learn/courses/30/lessons/150370?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(today, terms, privacies):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("2022.05.19", ["A 6", "B 12", "C 3"],
      ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]),
     [1, 3]),
    (("2020.01.01", ["Z 3", "D 5"],
      ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]),
     [1, 4, 5]),
]

run_tests(solution, test_cases)