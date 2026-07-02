# https://school.programmers.co.kr/learn/courses/30/lessons/176963?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(name, yearning, photo):
    # TODO: 직접 풀어보세요
    pass

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