# https://school.programmers.co.kr/learn/courses/30/lessons/42626?language=python3
# 유형: 힙

# Number of times solving questions: 1
# 2026-09-12

import heapq
import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(scoville, K):
    # 규칙 1. 모든 음식이 K 이상이 될 때까지 가장 안 매운 둘을 섞는다.
    #         새 음식 = 가장 안 매운 것 + 두 번째로 안 매운 것 * 2
    # 규칙 2. 섞은 횟수를 반환한다. 전부 K 이상으로 만들 수 없으면 -1.
    #
    # 가장 작은 음식 >= K ?
    #      ↙        ↘
    #    YES        NO
    #     ↓          ↓
    #  answer    음식이 2개 미만인가?
    #  return         ↙        ↘
    #               YES        NO
    #                ↓          ↓
    #               -1    가장 작은 음식 2개 꺼냄
    #                           ↓
    #                  new = first + second * 2
    #                           ↓
    #                     new 를 다시 넣음
    #                           ↓
    #                       answer++
    #                           ↓
    #                      (처음으로)

    answer = 0

    # heapq 는 기본이 최소 힙이다 (C++ priority_queue 가 기본 최대 힙인 것과 정반대).
    # heapify 는 제자리에서 리스트를 힙으로 만든다. 매개변수가 이미 복사본이라 안전하다.
    # 파이썬 정수는 크기 제한이 없어 C++에서 문제가 된 오버플로가 여기서는 생기지 않는다.
    heapq.heapify(scoville)

    while scoville[0] < K:
        # 섞을 때마다 둘이 나가고 하나가 들어와 크기가 1씩 준다.
        # 재료가 하나뿐이면 더 섞을 수 없다. (규칙 2)
        if len(scoville) < 2:
            return -1

        first_s = heapq.heappop(scoville)
        second_s = heapq.heappop(scoville)
        heapq.heappush(scoville, first_s + second_s * 2)   # (규칙 1)
        answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([1, 2, 3, 9, 10, 12], 7), 2),
]

run_tests(solution, test_cases)
