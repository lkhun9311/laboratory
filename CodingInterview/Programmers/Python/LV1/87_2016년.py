# https://school.programmers.co.kr/learn/courses/30/lessons/12901?language=python3

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(a, b):
    # 규칙 1. 2016년 1월 1일은 금요일이고, 2016년은 윤년이라 2월이 29일이다.
    # 규칙 2. "1월 1일부터 며칠 지났는가"를 구해 7로 나눈 나머지로 요일을 정한다.
    #        1월 1일 자신은 0일 지난 날이므로 b가 아니라 b - 1 이다.
    DAYS_IN_MONTH = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    WEEKDAYS = ["FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"]   # 1월 1일(금)부터 시작

    # a월 이전 달들을 통째로 더한다. a월 자신은 b일로 따로 세므로 제외한다.
    elapsed_days = b - 1
    for month in range(a - 1):
        elapsed_days += DAYS_IN_MONTH[month]

    return WEEKDAYS[elapsed_days % 7]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((5, 24), "TUE"),
    ((1, 1), "FRI"),
    ((1, 2), "SAT"),
    ((12, 31), "SAT"),
    ((2, 29), "MON"),
]

run_tests(solution, test_cases)
