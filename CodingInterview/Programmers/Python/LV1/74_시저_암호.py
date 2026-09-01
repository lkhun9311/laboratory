# https://school.programmers.co.kr/learn/courses/30/lessons/12926?language=python3

# Number of times solving questions: 1
# 2026-09-01

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s, n):
    # 규칙 1. 각 알파벳을 n칸 뒤로 민다. 공백은 아무리 밀어도 공백이다.
    # 규칙 2. 알파벳 끝을 넘으면 처음으로 돌아온다 (z + 1 = a, Z + 1 = A).
    #        n이 최대 25라 한 바퀴 이상 돌지 않으므로 26을 한 번만 빼면 된다.
    # 참고. 대문자와 소문자는 코드 구간이 다르다 (A~Z = 65~90, a~z = 97~122).
    #      그래서 넘침 판정 기준도 각각 'z' 와 'Z' 로 따로 봐야 한다.
    answer = ''

    for letter in s:
        if letter == " ":
            answer += " "
            continue

        shifted = ord(letter) + n

        if 'a' <= letter <= 'z' and shifted > ord('z'):
            shifted -= 26

        if 'A' <= letter <= 'Z' and shifted > ord('Z'):
            shifted -= 26

        answer += chr(shifted)

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("AB", 1), "BC"),
    (("z", 1), "a"),
    (("a B z", 4), "e F d"),
    (("Z", 1), "A"),
    (("AaZz", 25), "ZzYy"),
]

run_tests(solution, test_cases)
