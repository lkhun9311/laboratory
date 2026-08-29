# https://school.programmers.co.kr/learn/courses/30/lessons/12933?language=python3

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n):
    # 규칙. n의 각 자릿수를 큰 것부터 정렬해 하나의 정수로 되돌린다.
    #      문자열로 바꾸면 각 글자가 곧 자릿수라 쪼개기와 합치기가 모두 쉽다.
    #      sorted()는 문자열을 직접 받아 글자 리스트를 돌려주므로 list()가 필요 없다.
    return int("".join(sorted(str(n), reverse=True)))

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (118372, 873211),
    (1, 1),
    (10, 10),
    (1000, 1000),
    (8000000000, 8000000000),
    (123456789, 987654321),
]

run_tests(solution, test_cases)
