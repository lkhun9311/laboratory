# https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=python3

# Number of times solving questions: 1
# 2026-08-21

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(nums):
    # 규칙 1. 연구실에 있는 N마리 중 절반인 N/2마리만 가져갈 수 있다.
    # 규칙 2. 같은 종류는 같은 번호를 가진다. 그리고 구해야 하는 값은
    #        "몇 마리를 가져가느냐"가 아니라 "몇 종류를 가져가느냐"다.

    # 1. 가져갈 수 있는 마리 수. 종류를 아무리 많이 모아도 이 수를 넘을 수 없다. (규칙 1)
    take_limit = len(nums) // 2

    # 2. 연구실에 있는 종류의 가짓수. set이 같은 번호를 하나로 합쳐주므로
    #    남는 것은 서로 다른 번호뿐이다. 각 종류가 몇 마리인지는 답에 영향이 없다. (규칙 2)
    kinds = set(nums)

    # 3. 두 한도 중 작은 쪽이 답이다.
    #    종류가 모자라면 종류 수가, 가져갈 마리 수가 모자라면 그 수가 답을 가로막는다.
    return min(take_limit, len(kinds))

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([3, 1, 2, 3], 2),
    ([3, 3, 3, 2, 2, 4], 3),
    ([3, 3, 3, 2, 2, 2], 2),
]

run_tests(solution, test_cases)