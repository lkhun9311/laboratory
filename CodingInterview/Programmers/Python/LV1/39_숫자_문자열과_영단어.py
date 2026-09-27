# https://school.programmers.co.kr/learn/courses/30/lessons/81301?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s):
    answer = 0
    eng_to_num = {
        "zero": "0",
        "one": "1",
        "two": "2",
        "three": "3",
        "four": "4",
        "five": "5",
        "six": "6",
        "seven": "7",
        "eight": "8",
        "nine": "9"
    }

    for eng, num in eng_to_num.items():
        s = s.replace(eng, num)

    answer = int(s)
    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    ("one4seveneight", 1478),
    ("23four5six7", 234567),
    ("2three45sixseven", 234567),
    ("123", 123),

    # 아래는 직접 추가한 경계 케이스
    ("7", 7),                                                    # 한 글자
    ("nine", 9),                                                 # 한 단어
    ("1zero0zero", 1000),                                        # 0 이 중간에 섞임
    ("2000000000", 2000000000),                                  # 최댓값을 숫자로
    ("twozerozerozerozerozerozerozerozerozero", 2000000000),     # 최댓값을 전부 영단어로
]

run_tests(solution, test_cases)
