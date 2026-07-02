# https://school.programmers.co.kr/learn/courses/30/lessons/468370?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(message, spoiler_ranges):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("here is muzi here is a secret message", [[0, 3], [23, 28]]), 1),
    (("my phone number is 01012345678 and may i have your phone number", [[5, 5], [25, 28], [34, 40], [53, 59]]), 4),
]

run_tests(solution, test_cases)