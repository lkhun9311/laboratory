# https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=python3

# Number of times solving questions: 1
# 2026-08-21

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(array, commands):
    # 규칙 1. 명령 하나는 [i, j, k]이고 셋 다 1부터 세는 "몇 번째"다.
    #        파이썬 인덱스는 0부터 세므로 그대로 쓰면 한 칸씩 어긋난다.
    # 규칙 2. 명령마다 자르기 -> 정렬 -> k번째 뽑기를 거치며,
    #        결과는 명령이 주어진 순서 그대로 담아 돌려준다.

    answer = []

    for i, j, k in commands:
        # 1. i번째부터 j번째까지 자른 뒤 정렬한다.
        #    시작은 i번째이므로 i-1, 끝은 j를 그대로 쓴다.
        #    슬라이스가 끝 위치를 포함하지 않기 때문에, j번째까지 포함하려면 j로 끊어야 한다. (규칙 1)
        sorted_slice = sorted(array[i-1:j])

        # 2. 정렬한 조각에서 k번째를 뽑는다. k도 1부터 세므로 k-1. (규칙 1)
        #    append 순서가 곧 반환 순서가 된다. (규칙 2)
        answer.append(sorted_slice[k-1])

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]), [5, 6, 3]),
]

run_tests(solution, test_cases)