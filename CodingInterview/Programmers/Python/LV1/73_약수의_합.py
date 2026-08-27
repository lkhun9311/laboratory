# https://school.programmers.co.kr/learn/courses/30/lessons/12928?language=python3

# Number of times solving questions: 1
# 2026-08-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n):
    answer = 0

    i = 1
    while i*i <= n:
        if n%i == 0:
            answer += i
            if i != n//i:
                answer += n//i
        i += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (12, 28),
    (5, 6),
    (1, 1),
    (0, 0),
    (3000, 9360),
]

run_tests(solution, test_cases)
