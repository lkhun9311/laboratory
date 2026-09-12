# https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=python3
# 유형: 스택큐

# Number of times solving questions: 1
# 2026-09-12

from collections import deque
import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(priorities, location):
    # 규칙 1. 대기 큐 맨 앞을 꺼내, 큐 안에 더 높은 우선순위가 있으면 맨 뒤로 보낸다.
    # 규칙 2. 없으면 실행한다.
    # 규칙 3. location 번째(0-based) 프로세스가 몇 번째로 실행되는지(1-based) 반환한다.
    #
    #  맨 앞 프로세스를 본다   ← 큐가 빌 일은 없다 (찾는 프로세스는 반드시 실행된다)
    #          ↓
    #  더 높은 우선순위가 있나?
    #       ↙        ↘
    #     YES        NO
    #      ↓          ↓
    #  맨 뒤로 이동   실행 (popleft)
    #      ↓          ↓
    #  (처음으로)  실행 횟수 +1
    #                 ↓
    #         내가 찾던 프로세스?
    #            ↙        ↘
    #          YES        NO
    #           ↓          ↓
    #      실행 횟수 반환  (처음으로)

    executed = 0

    # 맨 뒤로 보낸 것을 다시 꺼내야 하므로 큐가 진짜로 필요하다.
    # 우선순위만 담으면 [1,1,9,1,1,1] 처럼 같은 값이 여럿일 때
    # 어느 것이 location 번째였는지 구분할 수 없다. (규칙 3)
    waiting = deque((priority, index) for index, priority in enumerate(priorities))

    while True:
        current = waiting[0]
        max_priority = max(priority for priority, _ in waiting)

        if current[0] < max_priority:
            # rotate(-1) 은 "맨 앞을 떼어 맨 뒤에 붙인다" 와 같다. (규칙 1)
            waiting.rotate(-1)
            continue

        waiting.popleft()
        executed += 1

        if current[1] == location:
            return executed

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([2, 1, 3, 2], 2), 1),
    (([1, 1, 9, 1, 1, 1], 0), 5),
]

run_tests(solution, test_cases)
