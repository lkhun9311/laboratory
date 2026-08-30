# https://school.programmers.co.kr/learn/courses/30/lessons/12925?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s):
    # 규칙. 부호가 붙을 수 있는 문자열을 정수로.
    #      int() 가 +/- 부호를 알아서 처리한다.
    #      (C++ 에서는 int(s) 가 형변환이라 안 되고 stoi(s) 를 써야 한다)
    return int(s)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("1234", 1234),
    ("-1234", -1234),
    ("+1234", 1234),
    ("1", 1),
    ("-9", -9),
    ("99999", 99999),
]

run_tests(solution, test_cases)
