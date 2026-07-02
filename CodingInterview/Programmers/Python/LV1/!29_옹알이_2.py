
# https://school.programmers.co.kr/learn/courses/30/lessons/133499?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(babbling):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (["aya", "yee", "u", "maa"], 1),
    (["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"], 2),
]

run_tests(solution, test_cases)