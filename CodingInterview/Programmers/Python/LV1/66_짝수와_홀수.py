# https://school.programmers.co.kr/learn/courses/30/lessons/12937?language=python3

# Number of times solving questions: 1
# 2026-07-04

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(num):
    return "Even" if num % 2 == 0 else "Odd"

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (100, "Even"),
    (3, "Odd"),
]

run_tests(solution, test_cases)