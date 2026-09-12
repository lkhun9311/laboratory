# https://school.programmers.co.kr/learn/courses/30/lessons/42583?language=python3
# 유형: 스택큐

# Number of times solving questions: 1
# 2026-09-12

from collections import deque
import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(bridge_length, weight, truck_weights):
    # 규칙 1. 트럭은 주어진 순서대로만 올라간다.
    # 규칙 2. 올라가서 내려오기까지 정확히 bridge_length 초.
    # 규칙 3. 다리 위 무게 합이 weight 를 넘으면 못 올라간다.
    #
    #  1초 경과 (answer++)
    #          ↓
    #  다리 맨 앞 칸을 내린다 (0이면 빈 칸)
    #  current_weight -= 내린 무게
    #          ↓
    #  대기 트럭이 남았나?
    #       ↙        ↘
    #     YES        NO
    #      ↓          ↓
    #  무게 여유 있나?  빈 칸(0) 밀어넣기
    #    ↙      ↘          ↓
    #  YES      NO     (처음으로)
    #   ↓        ↓
    #  올린다  빈 칸(0)
    #   ↓        ↓
    #     (처음으로)
    #
    #  종료: 다리 위 무게 0 이고 대기 트럭도 없음
    #
    # 다리를 bridge_length 칸짜리 컨베이어 벨트로 본다. 빈 칸은 0.
    # 칸 수가 고정이므로 "최대 동시 통행 대수"가 저절로 지켜진다.
    answer = 0
    bridge = deque([0] * bridge_length)
    truck = deque(truck_weights)
    current_weight = 0          # 매초 다시 더하지 않고 들고 다닌다

    while current_weight > 0 or len(truck) > 0:
        answer += 1

        current_weight -= bridge[0]     # 맨 앞 칸이 다리를 벗어난다 (규칙 2)
        bridge.popleft()

        if len(truck) > 0:
            truck_weight = truck[0]

            # 방금 한 대가 내려간 뒤의 무게로 판정해야 한다
            if current_weight + truck_weight <= weight:
                truck.popleft()
                current_weight += truck_weight
                bridge.append(truck_weight)
            else:
                bridge.append(0)
        else:
            bridge.append(0)

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((2, 10, [7, 4, 5, 6]), 8),
    ((100, 100, [10]), 101),
    ((100, 100, [10, 10, 10, 10, 10, 10, 10, 10, 10, 10]), 110),
]

run_tests(solution, test_cases)
