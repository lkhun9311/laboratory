# https://school.programmers.co.kr/learn/courses/30/lessons/77484?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def show_result(solution):
    if solution == 6:
        return 1
    elif solution == 5:
        return 2
    elif solution == 4:
        return 3
    elif solution == 3:
        return 4
    elif solution == 2:
        return 5
    else:
        return 6

def solution(lottos, win_nums):
    answer = []
    solution = 0

    for lotto in lottos:
        if lotto in win_nums:
            solution += 1

    count_0 = lottos.count(0)

    answer.append(show_result(solution + count_0))
    answer.append(show_result(solution))
    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]), [3, 5]),
    (([0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25]), [1, 6]),
    (([45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35]), [1, 1]),

    # 아래는 직접 추가한 경계 케이스
    (([1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12]), [6, 6]),      # 하나도 안 맞고 0 도 없음
    (([1, 2, 3, 4, 5, 6], [1, 8, 9, 10, 11, 12]), [6, 6]),      # 1 개 맞아도 6 등
    (([0, 2, 3, 4, 5, 6], [2, 8, 9, 10, 11, 12]), [5, 6]),      # 0 하나로 1 개 -> 2 개
    (([0, 0, 3, 4, 5, 6], [3, 4, 5, 6, 11, 12]), [1, 3]),       # 4 개 확정 + 0 두 개
]

run_tests(solution, test_cases)
