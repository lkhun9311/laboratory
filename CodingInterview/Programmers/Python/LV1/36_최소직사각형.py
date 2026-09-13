# https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=python3

# Number of times solving questions: 1
# 2026-09-13

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(sizes):
    # 규칙 1. 명함은 돌릴 수 있다 → 각 명함을 "긴 변, 짧은 변"으로 정규화할 수 있다.
    # 규칙 2. 그러면 지갑은 "가장 긴 긴변 x 가장 긴 짧은변" 하나로 정해진다.

    max_long = 0        # 긴 변들 중 최댓값 = 지갑의 가로
    max_short = 0       # 짧은 변들 중 최댓값 = 지갑의 세로

    for card in sizes:
        max_long = max(max_long, max(card))
        max_short = max(max_short, min(card))

    return max_long * max_short

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([[60, 50], [30, 70], [60, 30], [80, 40]], 4000),
    ([[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]], 120),
    ([[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]], 133),
]

run_tests(solution, test_cases)