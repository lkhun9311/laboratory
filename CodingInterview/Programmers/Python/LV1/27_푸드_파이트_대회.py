# https://school.programmers.co.kr/learn/courses/30/lessons/134240?language=python3

# Number of times solving questions: 1
# 2026-09-02

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(food):
    # 규칙 1. 두 선수가 똑같이 나눠 먹으므로 각 음식은 food[i] // 2 개씩. 홀수면 하나 남긴다.
    # 규칙 2. food[0] 은 물이고 가운데에 하나만 놓이므로 반복은 1번부터.
    # 규칙 3. 오른쪽은 왼쪽을 뒤집은 것 — 두 선수의 순서가 같아야 하므로.
    left = ""

    for number in range(1, len(food)):
        portion = food[number] // 2
        left += str(number) * portion

    return left + "0" + left[::-1]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([1, 3, 4, 6], "1223330333221"),
    ([1, 7, 1, 2], "111303111"),
    ([1, 2], "101"),
    ([1, 1, 2], "202"),
    ([1, 5, 5], "1122002211"[:4] + "0" + "1122"[::-1]),
    ([1, 1, 1, 1, 1, 1, 1, 1, 9], "8888" + "0" + "8888"),
]

run_tests(solution, test_cases)
