# https://school.programmers.co.kr/learn/courses/30/lessons/138477?language=python3

# Number of times solving questions: 1
# 2026-09-02

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(k, score):
    # 규칙. 상위 k개만 명예의 전당에 남기고, 매일 그중 최하위를 기록한다.
    #      정렬 후 자르기까지 하면 "이번 점수가 들어갔는지" 는 이미 결정된다.
    #      따로 판단하는 if 가 필요 없고, 마지막 원소가 곧 최하위다.
    answer = []
    arr_k = []

    for s in score:
        arr_k.append(s)
        arr_k.sort(reverse=True)
        arr_k = arr_k[:k]
        answer.append(arr_k[-1])
    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((3, [10, 100, 20, 150, 1, 100, 200]), [10, 10, 10, 20, 20, 100, 100]),
    ((4, [0, 300, 40, 300, 20, 70, 150, 50, 500, 1000]), [0, 0, 0, 0, 20, 40, 70, 70, 150, 300]),
]

run_tests(solution, test_cases)
