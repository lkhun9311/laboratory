# https://school.programmers.co.kr/learn/courses/30/lessons/131705?language=python3

# Number of times solving questions: 1
# 2026-09-02

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

from itertools import combinations


def solution(number):
    # 규칙. 세 학생의 번호 합이 0이면 삼총사. 그런 조합의 개수를 센다.
    #      길이가 최대 13이라 13C3 = 286가지뿐이므로 전부 확인해도 된다. (완전탐색)
    #      combinations 는 원래 순서를 지키며 3개를 뽑으므로
    #      같은 조합이 순서만 바뀌어 중복으로 나오는 일이 없다.
    #      (C++ 에는 이런 내장이 없어 반복문 세 겹으로 i < j < k 를 직접 만든다)
    answer = 0

    for trio in combinations(number, 3):
        if sum(trio) == 0:
            answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([-2, 3, 0, 2, -5], 2),
    ([-3, -2, -1, 0, 1, 2, 3], 5),
    ([1, -1, 0], 1),
    ([1, 1, 1], 0),
    ([0, 0, 0, 0], 4),
    ([0] * 13, 286),
]

run_tests(solution, test_cases)
