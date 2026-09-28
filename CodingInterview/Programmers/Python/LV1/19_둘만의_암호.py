# https://school.programmers.co.kr/learn/courses/30/lessons/155652?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s, skip, index):
    answer = ''

    for ch in s:
        count = 0

        while count < index:
            ch = chr((ord(ch)-ord('a')+1) % 26 + ord('a'))
            if ch not in skip:
                count += 1

        answer += ch

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("aukks", "wbqd", 5), "happy"),

    # 아래는 직접 추가한 경계 케이스
    (("a", "", 1), "b"),                    # 건너뛸 글자가 없다
    (("z", "", 1), "a"),                    # z 에서 한 칸 -> a 로 돌아온다
    (("a", "b", 1), "c"),                   # 바로 다음 글자를 건너뛴다
    (("a", "bcd", 1), "e"),                 # 연달아 건너뛴다
    (("z", "a", 1), "b"),                   # 끝에서 돌아온 자리가 건너뛸 글자
    (("aaa", "b", 2), "ddd"),               # 같은 글자 여러 개
    (("a", "", 20), "u"),                   # index 최대
]

run_tests(solution, test_cases)
