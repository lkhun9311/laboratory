# https://school.programmers.co.kr/learn/courses/30/lessons/82612?language=python3

# Number of times solving questions: 1
# 2026-09-12

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(price, money, count):
    # 규칙 1. c 번째 탑승 비용은 price * c 원 (c = 1 .. count).
    # 규칙 2. 총비용이 money 보다 많으면 모자란 금액을, 아니면 0 을 반환한다.
    #
    # 파이썬 정수는 크기 제한이 없어 오버플로가 없지만,
    # C++에서는 총비용이 78억이라 누적 변수를 long long 으로 잡아야 한다.
    remain = money

    for c in range(1, count + 1):
        remain -= price * c

    if remain >= 0:
        return 0

    return (-1) * remain

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((3, 20, 4), 10),
    ((1, 100, 5), 0),
    ((2500, 1, 2500), 7815624999),
]

run_tests(solution, test_cases)