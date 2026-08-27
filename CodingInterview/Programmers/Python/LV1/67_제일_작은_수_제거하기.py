# https://school.programmers.co.kr/learn/courses/30/lessons/12935?language=python3

# Number of times solving questions: 1
# 2026-08-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(arr):
    # 규칙 1. 가장 작은 수 하나를 뺀 배열을 돌려준다. 원소는 서로 다르므로 지울 대상은 정확히 하나다.
    # 규칙 2. 빈 배열이 되면 대신 [-1]을 돌려준다.

    # 1. 길이가 1이면 빼는 순간 비므로 먼저 걸러낸다. (규칙 2)
    #    arr[0]을 읽기 전에 검사해야 빈 입력에서도 안전하다.
    if len(arr) <= 1:
        return [-1]

    # 2. 최솟값을 찾아 그것만 빼고 나머지를 순서대로 모은다. (규칙 1)
    min_number = min(arr)

    return [x for x in arr if x != min_number]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([4, 3, 2, 1], [4, 3, 2]),
    ([10], [-1]),
    ([3, 1, 2], [3, 2]),
    ([1, 2, 3], [2, 3]),
    ([5, 9, 1, 7], [5, 9, 7]),
]

run_tests(solution, test_cases)
