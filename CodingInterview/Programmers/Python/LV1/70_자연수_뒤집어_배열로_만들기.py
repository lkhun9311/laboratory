# https://school.programmers.co.kr/learn/courses/30/lessons/12932?language=python3

# Number of times solving questions: 1
# 2026-08-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n):
    # 규칙. n의 각 자리 숫자를 뒤집은 순서로 배열에 담는다.

    # 1. 문자열로 바꾸면 자릿수가 곧 글자가 된다. [::-1] 은 뒤에서부터 읽기.
    reverse_n = str(n)[::-1]

    # 2. 글자 하나하나를 다시 정수로 바꿔 담는다.
    return [int(i) for i in reverse_n]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (12345, [5, 4, 3, 2, 1]),
    (7, [7]),
    (10, [0, 1]),
    (1000, [0, 0, 0, 1]),
    (10000000000, [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1]),
]

run_tests(solution, test_cases)
