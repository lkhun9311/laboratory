# https://school.programmers.co.kr/learn/courses/30/lessons/12917?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s):
    # 규칙. 문자를 큰 것부터 작은 순으로 정렬한다.
    #      "대문자는 소문자보다 작다"는 조건은 추가 처리를 요구하는 게 아니라
    #      문자 코드가 이미 그렇게 되어 있다는 안내다 ('A'=65 ... 'Z'=90, 'a'=97 ... 'z'=122).
    sorted_s = sorted(s, reverse=True)

    return "".join(sorted_s)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("Zbcdefg", "gfedcbZ"),
    ("gfedcbZ", "gfedcbZ"),
    ("a", "a"),
    ("AbCdEf", "fdbECA"),
    ("zZaA", "zaZA"),
]

run_tests(solution, test_cases)
