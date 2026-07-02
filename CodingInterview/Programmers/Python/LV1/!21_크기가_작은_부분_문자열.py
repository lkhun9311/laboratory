# https://school.programmers.co.kr/learn/courses/30/lessons/147355?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(t, p):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("3141592", "271"), 2),
    (("500220839878", "7"), 8),
    (("10203", "15"), 3),
]

run_tests(solution, test_cases)