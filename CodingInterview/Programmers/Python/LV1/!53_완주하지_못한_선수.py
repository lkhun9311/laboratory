# https://school.programmers.co.kr/learn/courses/30/lessons/42576?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(participant, completion):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["leo", "kiki", "eden"], ["eden", "kiki"]), "leo"),
    ((["marina", "josipa", "nikola", "vinko", "filipa"],
      ["josipa", "filipa", "marina", "nikola"]), "vinko"),
    ((["mislav", "stanko", "mislav", "ana"],
      ["stanko", "ana", "mislav"]), "mislav"),
]

run_tests(solution, test_cases)