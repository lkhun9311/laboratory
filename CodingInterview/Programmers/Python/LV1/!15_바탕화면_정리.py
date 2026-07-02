# https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(wallpaper):
    # TODO: 직접 풀어보세요
    pass

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([".#...", "..#..", "...#."], [0, 1, 3, 4]),
    (["..........", ".....#....", "......##..", "...##.....", "....#....."], [1, 3, 5, 8]),
    ([".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."], [0, 0, 7, 9]),
    (["..", "#."], [1, 0, 2, 1]),
]

run_tests(solution, test_cases)