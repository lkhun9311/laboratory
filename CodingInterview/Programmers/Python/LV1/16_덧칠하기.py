# https://school.programmers.co.kr/learn/courses/30/lessons/161989?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-24

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n, m, section):
    count = 0
    paint_until = 0

    for s in section:
        if s > paint_until:
            count += 1
            paint_until = s-1+m

    return count

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((8, 4, [2, 3, 6]), 2),
    ((5, 4, [1, 3]), 1),
    ((4, 1, [1, 2, 3, 4]), 4),

    # 아래는 직접 추가한 경계 케이스
    ((1, 1, [1]), 1),                                  # 최소 입력
    ((5, 5, [1, 2, 3, 4, 5]), 1),                      # 롤러가 벽 전체를 덮는다
    ((5, 4, [4, 5]), 1),                               # 롤러가 벽 끝을 넘어간다
    ((10, 2, [1, 5, 9]), 3),                           # 칠할 곳이 떨어져 있다
    ((100000, 1, list(range(1, 100001))), 100000),     # 최대 입력, 한 칸짜리 롤러
]

run_tests(solution, test_cases)
