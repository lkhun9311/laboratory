# https://school.programmers.co.kr/learn/courses/30/lessons/135808?language=python3

# Number of times solving questions: 1
# 2026-09-13

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(k, m, score):
    # 규칙 1. m개씩 묶고, 상자 가격 = (그 상자의 최저 점수) * m. 남는 사과는 버린다.
    #
    # 그리디 근거: 가격은 상자의 최솟값에만 좌우되므로 비슷한 점수끼리 묶어야
    #   높은 사과가 낮은 최솟값에 끌려가 낭비되지 않는다. 정렬하면 저절로 그렇게 된다.
    #   내림차순으로 m개씩 끊으면 각 묶음의 마지막 원소가 그 상자의 최솟값이다.

    result = 0

    score = sorted(score, reverse=True)
    box_count = len(score) // m         # 만들 수 있는 상자 수. 나머지는 버린다

    for t in range(box_count):
        result += m * score[(t + 1) * m - 1]

    return result

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((3, 4, [1, 2, 3, 1, 2, 3, 1]), 8),
    ((4, 3, [4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2]), 33),
]

run_tests(solution, test_cases)