# https://school.programmers.co.kr/learn/courses/30/lessons/72410?language=python3
# 출처: 2021 KAKAO BLIND RECRUITMENT

# Number of times solving questions: 1
# 2026-09-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(new_id):
    new_id = new_id.lower()

    for i in "~!@#$%^&*()=+[{]}:?,<>/":
        new_id = new_id.replace(i, "")

    while ".." in new_id:
        new_id = new_id.replace("..", ".")

    if new_id and new_id[0] == '.':
        new_id = new_id[1:]

    if new_id and new_id[-1] == '.':
        new_id = new_id[:-1]

    if not new_id:
        new_id = 'a'

    if len(new_id) >= 16:
        new_id = new_id[:15]
        if new_id[-1] == '.':
            new_id = new_id[:14]

    if len(new_id) <= 2:
        while len(new_id) < 3:
            new_id += new_id[-1]

    return new_id

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("...!@BaT#*..y.abcdefghijklm", "bat.y.abcdefghi"),
    ("z-+.^.", "z--"),
    ("=.=", "aaa"),
    ("123_.def", "123_.def"),
    ("abcdefghijklmn.p", "abcdefghijklmn"),

    # 아래는 직접 추가한 경계 케이스
    ("...", "aaa"),                       # 전부 마침표 -> 빈 문자열 -> a -> aaa
    ("a", "aaa"),                         # 한 글자 -> 마지막 글자 반복
    ("ab", "abb"),                        # 두 글자 -> 마지막 글자 반복
    ("abc", "abc"),                       # 딱 세 글자, 손대지 않음
    ("a" * 20, "a" * 15),                 # 16 자 이상 -> 15 자로 자름
    ("aaaaaaaaaaaaaa.b", "aaaaaaaaaaaaaa"),   # 15 자로 자른 끝이 마침표 -> 하나 더 제거
    ("!!!", "aaa"),                       # 금지 문자만 -> 빈 문자열
    ("A.B", "a.b"),                       # 대문자 소문자로
]

run_tests(solution, test_cases)
