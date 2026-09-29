# https://school.programmers.co.kr/learn/courses/30/lessons/17682?language=python3
# 출처: 2018 KAKAO BLIND RECRUITMENT

# Number of times solving questions: 1
# 2026-09-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(dartResult):
    result = []

    num = ""
    for dr in dartResult:
        if dr.isdigit():
            num += dr

        elif dr in "SDT":
            score = int(num)
            num = ""

            if dr == "S":
                score = score**1
            elif dr == "D":
                score = score**2
            elif dr == "T":
                score = score**3
            result.append(score)

        elif dr == "*":
            result[-1] *= 2

            if len(result)>1:
                result[-2] *= 2

        elif dr == "#":
            result[-1] *= -1

    return sum(result)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("1S2D*3T", 37),
    ("1D2S#10S", 9),
    ("1D2S0T", 3),
    ("1S*2T*3S", 23),
    ("1D#2S*3S", 5),
    ("1T2D3D#", -4),
    ("1D2S3T*", 59),

    # 아래는 직접 추가한 경계 케이스
    ("0S0S0S", 0),                  # 전부 0 점
    ("10S10S10S", 30),              # 두 자리 점수
    ("10T10T10T", 3000),            # 두 자리 + 세제곱
    # 1S -> 1, 첫 * 로 2 (앞 기회 없음). 2S -> 2, 두 번째 * 로 4 가 되고 직전 2 도 4 로.
    # 최종 4 + 4 + 3 = 11
    ("1S*2S*3S", 11),
    ("1S#2S#3S#", -6),              # 아차상만
    ("10D*10D*10D", 700),           # 두 자리 + 스타상 연속
]

run_tests(solution, test_cases)
