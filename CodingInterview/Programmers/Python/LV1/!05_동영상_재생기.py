# https://school.programmers.co.kr/learn/courses/30/lessons/340213?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(video_len, pos, op_start, op_end, commands):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("34:33", "13:00", "00:55", "02:55", ["next", "prev"]), "13:00"),
    (("10:55", "00:05", "00:15", "06:55", ["prev", "next", "next"]), "06:55"),
    (("07:22", "04:05", "00:15", "04:07", ["next"]), "04:17"),
]

run_tests(solution, test_cases)