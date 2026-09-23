# https://school.programmers.co.kr/learn/courses/30/lessons/42747?language=python3
# 출처: 정렬

# Number of times solving questions: 1
# 2026-09-23

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(citations):
    h = 0
    n = len(citations)
    result = []
    while h<=n:
        count = 0

        for citation in citations:
            if citation >= h:
                count += 1

        if count >= h:
            result.append(h)

        h += 1

    return max(result)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([3, 0, 6, 1, 5], 3),

    # 아래는 직접 추가한 경계 케이스 (앞선 오답에서 나온 반례들을 그대로 고정한다)
    ([0, 0, 3], 1),
    ([0, 0, 0, 0, 10], 1),
    ([0, 7, 3, 8, 4, 1, 2, 2], 3),
    ([7, 0, 11, 2, 0, 1, 9, 0], 3),
    ([0], 0),                       # 논문 한 편, 인용 0
    ([1], 1),                       # 논문 한 편, 인용 1
    ([10, 10, 10], 3),              # 전부 많이 인용 — h 는 논문 수로 막힌다
    ([0, 0, 0], 0),                 # 전부 0
]

run_tests(solution, test_cases)
