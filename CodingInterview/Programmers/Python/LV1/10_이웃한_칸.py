# https://school.programmers.co.kr/learn/courses/30/lessons/250125?language=python3

# Number of times solving questions: 1
# 2026-09-13

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(board, h, w):
    # 규칙 1. board[h][w] 와 상하좌우로 맞닿은 칸 중 같은 색인 칸의 개수.
    # 규칙 2. 탐색은 없고 이웃 네 칸만 본다.

    answer = 0

    # 방향 배열. 상 하 좌 우 순서로 맞춰 둔다.
    dh = [-1, 1, 0, 0]
    dw = [0, 0, -1, 1]

    color = board[h][w]
    n = len(board)

    for i in range(4):
        new_h = h + dh[i]
        new_w = w + dw[i]

        # 범위 검사를 board 접근보다 먼저 한다.
        # 파이썬은 음수 인덱스가 뒤에서 세는 것이라 조용히 틀린 칸을 읽는다 - C++보다 더 고약하다.
        if new_h < 0 or new_h >= n or new_w < 0 or new_w >= n:
            continue

        if color == board[new_h][new_w]:
            answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([["blue", "red", "orange", "red"], ["red", "red", "blue", "orange"], ["blue", "orange", "red", "red"], ["orange", "orange", "red", "blue"]], 1, 1), 2),
    (([["yellow", "green", "blue"], ["blue", "green", "yellow"], ["yellow", "blue", "blue"]], 0, 1), 1),
]

run_tests(solution, test_cases)