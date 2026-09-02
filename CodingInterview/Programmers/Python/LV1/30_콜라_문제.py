# https://school.programmers.co.kr/learn/courses/30/lessons/132267?language=python3

# Number of times solving questions: 1
# 2026-09-02

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(a, b, n):
    # 규칙. 빈 병 a개를 주면 콜라 b병을 받는다. 마신 콜라도 빈 병이 되어 다시 교환에 쓰인다.
    #      보유 빈 병이 a개 미만이면 더 교환할 수 없다.
    answer = 0

    while n >= a:
        trade_count = n//a                    # 이번에 몇 번 교환할 수 있나
        received_bottle = trade_count*b       # 받은 콜라
        remain_bottle = n%a                   # 교환에 못 쓰고 남은 빈 병

        answer += received_bottle
        n = remain_bottle + received_bottle    # 남은 것 + 마시고 생긴 빈 병

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((2, 1, 20), 19),
    ((3, 1, 20), 9),
    ((4, 1, 10), 3),
    ((5, 2, 100), 64),
    ((3, 2, 10), 16),
]

run_tests(solution, test_cases)
