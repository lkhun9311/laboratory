# https://school.programmers.co.kr/learn/courses/30/lessons/42586?language=python3
# 유형: 스택큐

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(progresses, speeds):
    # 규칙 1. 진도가 100 이상이 되면 완성. 배포는 앞에서부터만 된다.
    # 규칙 2. 뒤 기능이 먼저 끝나도 앞 기능을 기다렸다 함께 나간다.

    answer = []

    # 1단계. 각 작업의 소요 일수. -(-a // b) 가 파이썬의 올림 나눗셈 관용구다.
    #        C++에서는 (need + speed - 1) / speed 를 쓴다.
    days = [-(-(100 - p) // s) for p, s in zip(progresses, speeds)]

    # 2단계. 한 그룹의 배포일은 그 그룹 첫 작업의 일수다.
    #        뒤 작업이 그 날보다 빨리 끝나면 함께, 늦으면 거기서 새 그룹이 시작된다. (규칙 2)
    deploy_day = days[0]
    count = 1

    for day in days[1:]:
        if deploy_day >= day:
            count += 1
        else:
            answer.append(count)
            count = 1
            deploy_day = day

    # 루프는 새 그룹이 시작될 때 직전 그룹을 확정하므로 마지막 그룹이 남는다.
    answer.append(count)

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([93, 30, 55], [1, 30, 5]), [2, 1]),
    (([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]), [1, 3, 2]),
]

run_tests(solution, test_cases)
