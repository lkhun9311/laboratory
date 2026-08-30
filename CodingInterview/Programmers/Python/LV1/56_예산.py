# https://school.programmers.co.kr/learn/courses/30/lessons/12982?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(d, budget):
    # 규칙. 신청 금액은 전액 지원하거나 아예 안 하거나 둘 중 하나다.
    #      "지원 부서 수"를 최대로 하는 것이 목표이므로 싼 부서부터 채우는 것이 항상 최적이다.
    #      (어떤 답이 k개라면 그 k개를 가장 싼 k개로 바꿔도 총액이 늘지 않으므로)
    # 주의. d.sort() 는 호출한 쪽의 리스트까지 정렬한다. 원본을 지키려면 sorted(d) 를 쓴다.
    answer = 0
    cost = 0
    d.sort()

    for c in d:
        cost += c
        if cost <= budget:      # 예산과 같아지는 것은 허용
            answer += 1
        else:
            break

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([1, 3, 2, 5, 4], 9), 3),
    (([2, 2, 3, 3], 10), 4),
    (([5, 1, 1], 2), 2),
    (([1, 2, 3], 6), 3),
    (([2], 1), 0),
]

run_tests(solution, test_cases)
