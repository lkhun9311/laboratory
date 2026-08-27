# https://school.programmers.co.kr/learn/courses/30/lessons/12948?language=python3

# Number of times solving questions: 1
# 2026-08-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(phone_number):
    # 규칙. 뒤 4자리만 남기고 앞은 전부 *로 가린다. 길이는 4 이상이라 가릴 개수는 0 이상이다.
    tmp_number_size = len(phone_number) - 4

    return "*" * tmp_number_size + phone_number[-4:]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("01033334444", "*******4444"),
    ("027778888", "*****8888"),
    ("4444", "4444"),
    ("54321", "*4321"),
    ("12345678901234567890", "****************7890"),
]

run_tests(solution, test_cases)
