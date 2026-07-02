# https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=python3

# Number of times solving questions: 1
# 2026-06-20

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(arr):
    # 첫 원소는 무조건 포함 (단일 원소 입력도 이 한 줄로 커버)
    result = [arr[0]]

    # 인접한 두 원소를 비교하며 직전과 다른 값만 추가
    for i in range(len(arr) - 1):
        current_num = arr[i]
        next_num = arr[i + 1]

        if current_num != next_num:  # 연속 중복이 아니면 남긴다
            result.append(next_num)

    return result

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([1, 1, 3, 3, 0, 1, 1], [1, 3, 0, 1]),
    ([4, 4, 4, 3, 3], [4, 3]),
]

run_tests(solution, test_cases)