# https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=python3

# Number of times solving questions: 1
# 2026-06-17

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n, lost, reserve):
    need = set(lost) - set(reserve)
    give = set(reserve) - set(lost)

    for g in sorted(give):
        if g-1 in need:
            need.remove(g-1)
        elif g+1 in need:
            need.remove(g+1)

    return n - len(need)

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((5, [2, 4], [1, 3, 5]), 5),
    ((5, [2, 4], [3]), 4),
    ((3, [3], [1]), 2),
]

run_tests(solution, test_cases)