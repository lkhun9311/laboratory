# https://school.programmers.co.kr/learn/courses/30/lessons/12921?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-23

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

import math

def solution(n):
    visited = [False for _ in range(n+1)]
    visited[0] = True
    visited[1] = True
    sqrt_number = int(math.sqrt(n))

    for number in range(2, sqrt_number+1):
        if visited[number]:
            continue
        start = number*number
        visited[start::number] = [True]*len(range(start, n+1, number))

    return visited.count(False)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (10, 4),
    (5, 3),

    # 아래는 직접 추가한 경계 케이스
    (2, 1),                 # 최소 입력
    (3, 2),
    (4, 2),                 # 4 = 2*2 는 소수가 아니다
    (25, 9),                # 25 = 5*5 — sqrt 상한 처리를 확인한다
    (100, 25),
    (1000, 168),
    (1000000, 78498),       # 제한 최대
]

# 지우기를 number 가 아니라 number*number 에서 시작하는 이유:
# range(number, n+1, number) 로 시작하면 첫 대상이 number 자신이라 소수를 지워 버린다.
# 실제로 n=10 에서 답이 4 가 아니라 2 로 나왔다 (2026-09-23 실측, 2~3000 중 2997 건 오답).

run_tests(solution, test_cases)
