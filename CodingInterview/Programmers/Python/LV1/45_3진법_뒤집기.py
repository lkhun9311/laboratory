# https://school.programmers.co.kr/learn/courses/30/lessons/68935?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n):
    # 규칙. n을 3진법으로 바꿔 앞뒤로 뒤집은 뒤 다시 10진법으로.
    #      3진법 문자열을 만드는 내장 함수는 없다 (bin/oct/hex 는 2/8/16 전용).
    #      읽는 쪽은 int(s, 3) 이 해준다 — 단, "s를 3진법으로 해석" 이지 "3진법으로 변환"이 아니다.
    digits = ""
    while n > 0:
        digits = str(n%3) + digits    # 앞에 붙여야 정상 순서의 3진법 표기
        n //= 3

    return int(digits[::-1], 3)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (45, 7),
    (125, 229),
    (1, 1),
    (3, 1),
    (100000000, 56480240),
]

run_tests(solution, test_cases)
