# https://school.programmers.co.kr/learn/courses/30/lessons/176963?language=python3

# Number of times solving questions: 1
# 2026-09-13

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(name, yearning, photo):
    # 규칙 1. name[i] 를 그리워하는 정도가 yearning[i] 다.
    # 규칙 2. 사진마다 찍힌 사람들의 점수 합. name 에 없는 사람은 0점.

    answer = []

    # 이름 -> 점수 표. 사진마다 name 을 훑으면 O(사진수 x 인원 x name) 이 된다.
    score_table = {}
    for idx, n in enumerate(name):
        score_table[n] = yearning[idx]

    for persons in photo:
        score = 0
        for person in persons:
            # in 으로 확인한다. score_table[person] 을 바로 쓰면 KeyError 다.
            if person in score_table:
                score += score_table[person]
        answer.append(score)

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["may", "kein", "kain", "radi"], [5, 10, 1, 3],
      [["may", "kein", "kain", "radi"], ["may", "kein", "brin", "deny"], ["kon", "kain", "may", "coni"]]),
     [19, 15, 6]),
    ((["kali", "mari", "don"], [11, 1, 55],
      [["kali", "mari", "don"], ["pony", "tom", "teddy"], ["con", "mona", "don"]]),
     [67, 0, 55]),
    ((["may", "kein", "kain", "radi"], [5, 10, 1, 3],
      [["may"], ["kein", "deny", "may"], ["kon", "coni"]]),
     [5, 15, 0]),
]

run_tests(solution, test_cases)