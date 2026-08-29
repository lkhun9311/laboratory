# https://school.programmers.co.kr/learn/courses/30/lessons/12924?language=python3
# 유형: 구현

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n):
    # 규칙. n을 연속한 자연수들의 합으로 쓰는 방법의 수.
    #      시작 숫자를 1부터 n//2까지 바꿔가며 전부 시도한다. (완전탐색)
    #      n 자기 자신(항이 하나뿐인 경우)은 미리 1로 세어둔다.
    count = 1

    for start in range(1, n//2 + 1):
        total = start
        number = start

        while total < n:
            number += 1
            total += number

        if total == n:
            count += 1

    return count

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (15, 4),
    (1, 1),
    (2, 1),
    (3, 2),
    (10, 2),
]

run_tests(solution, test_cases)
