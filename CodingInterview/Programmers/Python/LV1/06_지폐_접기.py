# https://school.programmers.co.kr/learn/courses/30/lessons/340199?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(wallet, bill):
    answer = 0
    wallet.sort()
    bill.sort()

    while wallet[0]<bill[0] or wallet[1]<bill[1]:
        bill[1] //= 2
        answer += 1
        wallet.sort()
        bill.sort()

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    (([10, 20], [20, 10]), 0),          # 돌리면 바로 들어간다
    (([1, 1], [1, 1]), 0),              # 같은 크기
    (([5, 5], [10, 10]), 2),            # 두 번 접는다
    (([30, 15], [26, 17]), 1),          # 한 번 접으면 들어간다
    (([3, 3], [7, 3]), 1),              # 버림이 필요하다 (7 -> 3)
    (([1, 1], [4, 1]), 2),              # 4 -> 2 -> 1
    (([1, 1], [1000000000, 1]), 29),    # 최댓값을 1x1 지갑에
]

run_tests(solution, test_cases)
