# https://school.programmers.co.kr/learn/courses/30/lessons/147355?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(t, p):
    # 규칙. t 에서 p 와 길이가 같은 부분문자열 중, p 이하인 것의 개수.
    #      p 는 반복 내내 바뀌지 않으므로 변환은 반복문 밖에서 한 번만 한다.
    #      (C++ 에서는 p 가 최대 18자리라 stoi 가 아니라 stoll 을 써야 한다)
    answer = 0
    t_size = len(t)
    p_size = len(p)
    p_number = int(p)

    # 시작 위치는 0 부터 t_size - p_size 까지. 그 뒤로는 p_size 만큼 못 채운다.
    for i in range(t_size - p_size + 1):
        part = t[i:i+p_size]
        if int(part) <= p_number:
            answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("3141592", "271"), 2),
    (("500220839878", "7"), 8),
    (("10203", "15"), 3),
    (("0000", "0"), 4),
    (("999999999999999999", "999999999999999999"), 1),
    (("123", "123"), 1),
]

run_tests(solution, test_cases)
