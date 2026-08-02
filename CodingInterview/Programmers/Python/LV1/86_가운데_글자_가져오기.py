# https://school.programmers.co.kr/learn/courses/30/lessons/12903?language=python3

# Number of times solving questions: 1
# 2026-08-02

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(s):
    is_even = len(s) % 2 == 0
    mid = len(s) // 2  # 홀수면 곧 가운데 인덱스, 짝수면 가운데 두 글자 중 뒤쪽

    # 슬라이싱은 끝 인덱스를 제외하므로 두 경우 모두 끝은 mid + 1
    # 짝수일 때만 시작을 한 칸 앞으로 당겨 두 글자를 잡는다
    return s[mid - 1:mid + 1] if is_even else s[mid:mid + 1]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ("abcde", "c"),
    ("qwer", "we"),
]

run_tests(solution, test_cases)