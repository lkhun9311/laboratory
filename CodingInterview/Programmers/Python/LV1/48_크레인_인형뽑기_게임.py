# https://school.programmers.co.kr/learn/courses/30/lessons/64061?language=python3

# Number of times solving questions: 1
# 2026-09-12

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(board, moves):
    # 규칙 1. board 는 위에서 아래로 쌓인 격자. 0 은 빈 칸.
    # 규칙 2. moves[i] 번째 열에서 가장 위 인형 하나를 집는다. 빈 열이면 아무 일도 없다.
    # 규칙 3. 바구니에 같은 인형이 연속 두 개면 둘 다 사라진다.
    #         사라지면 그 아래가 새 맨 위가 되어 다시 비교된다 -> 스택이 맞다.

    answer = 0
    rows = len(board)
    cols = len(board[0])

    # 스택 개수는 "열" 개수다. 정사각 격자라 rows 로 써도 우연히 동작하지만 의미가 다르다.
    stacks = [[] for _ in range(cols)]

    # 아래 행부터 넣으므로 리스트의 끝이 곧 "가장 위 인형"이 된다.
    for col in range(cols):
        for row in board[::-1]:
            doll = row[col]
            if doll != 0:
                stacks[col].append(doll)

    basket = []
    for move in moves:
        col_stack = stacks[move - 1]

        if not col_stack:
            continue                # 빈 열 (규칙 2)

        doll = col_stack.pop()
        if basket and basket[-1] == doll:
            basket.pop()            # 둘 다 사라진다 (규칙 3)
            answer += 2
        else:
            basket.append(doll)

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([[0, 0, 0, 0, 0],
       [0, 0, 1, 0, 3],
       [0, 2, 5, 0, 1],
       [4, 2, 4, 4, 2],
       [3, 5, 1, 3, 1]], [1, 5, 3, 5, 1, 2, 1, 4]), 4),
]

run_tests(solution, test_cases)