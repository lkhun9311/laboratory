# https://school.programmers.co.kr/learn/courses/30/lessons/12910?language=python3

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(arr, divisor):
    # 규칙. divisor로 나누어떨어지는 값만 골라 오름차순으로 돌려준다.
    #      하나도 없으면 [-1]. 거른 뒤에 정렬해야 정렬 대상이 최소가 된다.
    answer = []

    for number in arr:
        if number%divisor == 0:
            answer.append(number)

    if not answer:
        return [-1]

    return sorted(answer)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([5, 9, 7, 10], 5), [5, 10]),
    (([2, 36, 1, 3], 1), [1, 2, 3, 36]),
    (([3, 2, 6], 10), [-1]),
    (([7], 7), [7]),
    (([100, 50, 25], 25), [25, 50, 100]),
]

run_tests(solution, test_cases)
