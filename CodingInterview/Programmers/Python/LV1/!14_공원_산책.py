# https://school.programmers.co.kr/learn/courses/30/lessons/172928?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(park, routes):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["SOO", "OOO", "OOO"], ["E 2", "S 2", "W 1"]), [2, 1]),
    ((["SOO", "OXX", "OOO"], ["E 2", "S 2", "W 1"]), [0, 1]),
    ((["OSO", "OOO", "OXO", "OOO"], ["E 2", "S 3", "W 1"]), [0, 0]),
]

run_tests(solution, test_cases)