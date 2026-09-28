# https://school.programmers.co.kr/learn/courses/30/lessons/389478?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n, w, num):
    answer = 0
    rows = (n+w-1)//w
    matrix = [[0]*w for _ in range(rows)]

    target_row = -1
    target_col = -1
    number = 1
    for row in range(rows):
        if row%2 == 0:
            for col in range(w):
                matrix[row][col] = number
                if number == num:
                    target_row = row
                    target_col = col
                if number == n:
                    break
                number += 1
        else:
            for col in range(w-1, -1, -1):
                matrix[row][col] = number
                if number == num:
                    target_row = row
                    target_col = col
                if number == n:
                    break
                number += 1

    for row in range(target_row, rows):
        if matrix[row][target_col] != 0:
            answer += 1
    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    ((22, 6, 8), 3),
    ((13, 3, 6), 4),

    # 아래는 직접 추가한 경계 케이스
    ((1, 1, 1), 1),             # 상자 하나
    ((5, 5, 3), 1),             # 한 줄만 있다 (위에 아무것도 없음)
    ((10, 1, 1), 10),           # 한 칸씩 쌓인 탑의 맨 아래
    ((10, 1, 10), 1),           # 한 칸씩 쌓인 탑의 맨 위
    ((7, 3, 1), 3),             # 마지막 줄이 덜 찼다 — 그 열은 비어 있음
]

run_tests(solution, test_cases)
