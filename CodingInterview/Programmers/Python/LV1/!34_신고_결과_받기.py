# https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(id_list, report, k):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["muzi", "frodo", "apeach", "neo"],
      ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"],
      2), [2, 1, 1, 0]),
    ((["con", "ryan"],
      ["ryan con", "ryan con", "ryan con", "ryan con"],
      3), [0, 0]),
]

run_tests(solution, test_cases)