# https://school.programmers.co.kr/learn/courses/30/lessons/12943?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def is_even(num):
    return num%2 == 0


def solution(num):
    # 규칙. 짝수면 2로 나누고 홀수면 3배+1. 1이 될 때까지의 횟수를 센다.
    #      500번 안에 1이 되지 않으면 -1. 500번 "까지"는 인정되므로 검사는 >= 500.
    #      (1~800만 중 정확히 501번 걸리는 입력이 19개 있어 이 경계가 실제로 갈린다)
    answer = 0

    while num > 1:
        if answer>=500:
            return -1
        if is_even(num):
            num //= 2
        else:
            num = num*3 + 1
        answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (6, 8),
    (16, 4),
    (626331, -1),
    (1, 0),
]

run_tests(solution, test_cases)
