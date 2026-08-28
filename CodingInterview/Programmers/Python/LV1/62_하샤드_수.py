# https://school.programmers.co.kr/learn/courses/30/lessons/12947?language=python3

# Number of times solving questions: 1
# 2026-08-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(x):
    # 규칙. 자릿수의 합으로 x가 나누어떨어지면 하샤드 수다.
    #      자릿수 합을 구하는 반복문은 값을 0까지 깎아야 끝나므로,
    #      나중에 나눌 원본 x는 건드리지 않고 복사본을 깎는다.
    remaining = x
    digit_sum = 0

    while remaining > 0:
        digit_sum += remaining % 10
        remaining //= 10

    return x % digit_sum == 0

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (10, True),
    (12, True),
    (11, False),
    (13, False),
]

run_tests(solution, test_cases)
