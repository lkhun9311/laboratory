# https://school.programmers.co.kr/learn/courses/30/lessons/258712?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(friends, gifts):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]), 2),
    ((["joy", "brad", "alessandro", "conan", "david"], ["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]), 4),
    ((["a", "b", "c"], ["a b", "b a", "c a", "a c", "a c", "c a"]), 0),
]

run_tests(solution, test_cases)