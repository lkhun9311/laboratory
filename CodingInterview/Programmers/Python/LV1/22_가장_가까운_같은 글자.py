# https://school.programmers.co.kr/learn/courses/30/lessons/142086?language=python3

# Number of times solving questions: 1
# 2026-09-02

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s):
    # 규칙. 각 위치마다 "앞에 나온 같은 글자까지의 거리". 없으면 -1.
    #      뒤로 훑으면 최악 O(n^2) (10,000자에서 약 0.5초).
    #      각 글자가 마지막으로 나온 위치만 기억하면 한 번의 순회로 끝난다. O(n)
    answer = []
    last_seen = {}

    for i, letter in enumerate(s):
        if letter in last_seen:
            answer.append(i - last_seen[letter])
        else:
            answer.append(-1)

        last_seen[letter] = i   # 값을 구한 "뒤에" 갱신해야 자기 자신을 찾지 않는다

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("banana", [-1, -1, -1, 2, 2, 2]),
    ("foobar", [-1, -1, 1, -1, -1, -1]),
    ("a", [-1]),
    ("aa", [-1, 1]),
    ("abcabc", [-1, -1, -1, 3, 3, 3]),
]

run_tests(solution, test_cases)
