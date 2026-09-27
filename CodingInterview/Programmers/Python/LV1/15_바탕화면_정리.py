# https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(wallpaper):
    wp_rows = len(wallpaper)
    wp_cols = len(wallpaper[0])
    lux, luy, rdx, rdy = wp_rows, wp_cols, 0, 0

    for row in range(wp_rows):
        for col in range(wp_cols):
            if wallpaper[row][col] == "#":
                lux = min(lux, row)
                luy = min(luy, col)
                rdx = max(rdx, row+1)
                rdy = max(rdy, col+1)

    return [lux, luy, rdx, rdy]

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    ([".#...", "..#..", "...#."], [0, 1, 3, 4]),
    (["..........", ".....#....", "......##..", "...##.....", "....#....."], [1, 3, 5, 8]),
    ([".##...####", "#..#.#....", "#.#.#.#..#", "#..#.#....", ".##...####"], [0, 0, 5, 10]),
    (["..", "#."], [1, 0, 2, 1]),

    # 아래는 직접 추가한 경계 케이스
    (["#"], [0, 0, 1, 1]),                       # 1x1 에 파일 하나
    (["...", "...", "..#"], [2, 2, 3, 3]),       # 오른쪽 아래 끝
    (["#.#", "...", "..."], [0, 0, 1, 3]),       # 한 행에 흩어져 있음
    (["#..", "...", "#.."], [0, 0, 3, 1]),       # 한 열에 흩어져 있음
]

run_tests(solution, test_cases)
