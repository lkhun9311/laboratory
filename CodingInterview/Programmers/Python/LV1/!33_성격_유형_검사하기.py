# https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(survey, choices):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["AN", "CF", "MJ", "RT", "NA"], [5, 3, 2, 7, 5]), "TCMA"),
    ((["TR", "RT", "TR"], [7, 1, 3]), "RCJA"),
]

run_tests(solution, test_cases)