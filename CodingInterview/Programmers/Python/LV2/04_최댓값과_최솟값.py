# https://school.programmers.co.kr/learn/courses/30/lessons/12939?language=python3
# 유형: 구현

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s):
    # 규칙. 공백으로 구분된 정수들 중 최솟값과 최댓값을 "최솟값 최댓값" 문자열로 돌려준다.
    #      쪼갠 조각은 문자열이므로 반드시 int로 바꾼다.
    #      문자열끼리 비교하면 사전순이 되어 "10" < "2" 가 참이 된다.
    nums = [int(x) for x in s.split()]

    return f"{min(nums)} {max(nums)}"

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("1 2 3 4", "1 4"),
    ("-1 -2 -3 -4", "-4 -1"),
    ("-1 -1", "-1 -1"),
    ("1 10 2", "1 10"),
    ("100 -100", "-100 100"),
]

run_tests(solution, test_cases)
