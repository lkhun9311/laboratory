# https://school.programmers.co.kr/learn/courses/30/lessons/72410?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(new_id):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("...!@BaT#*..y.abcdefghijklm", "bat.y.abcdefghi"),
    ("z-+.^.", "z--"),
    ("=.=", "aaa"),
    ("123_.def", "123_.def"),
    ("abcdefghijklmn.p", "abcdefghijklmn"),
]

run_tests(solution, test_cases)