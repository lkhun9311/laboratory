# https://school.programmers.co.kr/learn/courses/30/lessons/81301?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("one4seveneight", 1478),
    ("23four5six7", 234567),
    ("2three45sixseven", 234567),
    ("123", 123),
]

run_tests(solution, test_cases)