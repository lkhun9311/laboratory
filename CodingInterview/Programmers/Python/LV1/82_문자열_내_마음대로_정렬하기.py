# https://school.programmers.co.kr/learn/courses/30/lessons/12915?language=python3

# Number of times solving questions: 1
# 2026-09-12

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(strings, n):
    # 규칙 1. 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬한다.
    # 규칙 2. n번째 글자가 같으면 그들끼리는 사전순으로 놓는다.

    # key 로 튜플을 주면 앞에서부터 순서대로 비교한다.
    # x[n] 으로 먼저 가르고, 같을 때만 x 전체(사전순)로 넘어간다. (규칙 1, 2)
    #
    # C++에서는 key 대신 "a 가 b 보다 먼저인가"에 답하는 비교 함수를 직접 쓴다.
    # 이 한 줄이 C++에서는 if 두 줄이 된다.
    return sorted(strings, key=lambda x: (x[n], x))

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["sun", "bed", "car"], 1), ["car", "bed", "sun"]),
    ((["abce", "abcd", "cdx"], 2), ["abcd", "abce", "cdx"]),
]

run_tests(solution, test_cases)