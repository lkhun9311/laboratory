# https://school.programmers.co.kr/learn/courses/30/lessons/42889?language=python3
# 출처: 2019 KAKAO BLIND RECRUITMENT

# Number of times solving questions: 1
# 2026-09-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(N, stages):
    count = [0]*(N+2)

    for stage in stages:
        count[stage] += 1

    users = len(stages)

    result = []
    for i in range(1, N+1):
        if users == 0:
            failure = 0
        else:
            failure = count[i]/users

        result.append((i, failure))
        users -= count[i]

    result.sort(key=lambda x: (-x[1], x[0]))
    return [i for i, failure in result]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((5, [2, 1, 2, 6, 2, 4, 3, 3]), [3, 4, 2, 1, 5]),
    ((4, [4, 4, 4, 4, 4]), [4, 1, 2, 3]),

    # 아래는 직접 추가한 경계 케이스
    ((1, [1]), [1]),                                  # 스테이지 하나, 아직 못 깬 사람
    ((1, [2]), [1]),                                  # 스테이지 하나, 전부 통과 (실패율 0)
    ((3, [1, 1, 1]), [1, 2, 3]),                      # 1 에서 전원 멈춤 — 뒤는 도달자 0
    ((3, [4, 4, 4]), [1, 2, 3]),                      # 전원 클리어 — 전부 실패율 0
    # 1번: 3명 중 0명 = 0, 2번: 3명 중 2명 = 2/3, 3번: 1명 중 1명 = 1 -> 내림차순 3, 2, 1
    ((3, [2, 2, 3]), [3, 2, 1]),
    # 1번: 3명 중 1명 = 1/3, 2번: 2명 중 1명 = 1/2, 3번: 1명 중 1명 = 1 -> 내림차순 3, 2, 1
    ((3, [1, 2, 3]), [3, 2, 1]),
]

run_tests(solution, test_cases)
