# https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(sizes):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([[60, 50], [30, 70], [60, 30], [80, 40]], 4000),
    ([[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]], 120),
    ([[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]], 133),
]

run_tests(solution, test_cases)