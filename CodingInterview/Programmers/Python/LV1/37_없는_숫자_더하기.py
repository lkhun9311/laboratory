# https://school.programmers.co.kr/learn/courses/30/lessons/86051?language=python3

# Number of times solving questions: 1
# 2026-08-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(numbers):
    # 규칙. 0~9 중 numbers에 없는 숫자들의 합을 구한다.
    #      numbers의 원소는 서로 다르므로 개수를 셀 필요가 없다 -> set으로 충분하다.
    all_digits = set(range(10))
    given_digits = set(numbers)

    missing_digits = all_digits - given_digits
    return sum(missing_digits)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([1, 2, 3, 4, 6, 7, 8, 0], 14),
    ([5, 8, 4, 0, 6, 7, 9], 6),
    ([0], 45),
    ([0, 1, 2, 3, 4, 5, 6, 7, 8], 9),
]

run_tests(solution, test_cases)
