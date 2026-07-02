# https://school.programmers.co.kr/learn/courses/30/lessons/17682?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(dartResult):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("1S2D*3T", 37),
    ("1D2S#10S", 9),
    ("1D2S0T", 3),
    ("1S*2T*3S", 23),
    ("1D#2S*3S", 5),
    ("1T2D3D#", -4),
    ("1D2S3T*", 59),
]

run_tests(solution, test_cases)