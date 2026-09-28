# https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=python3
# 출처: 완전탐색

# Number of times solving questions: 1
# 2026-09-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(answers):
    result = []
    patterns = [
        [1,2,3,4,5],
        [2,1,2,3,2,4,2,5],
        [3,3,1,1,2,2,4,4,5,5]
    ]

    scores = [0,0,0]

    for i, answer in enumerate(answers):
        for j, pattern in enumerate(patterns):
            if answer == pattern[i%len(pattern)]:
                scores[j] += 1

    max_score = max(scores)
    for index, score in enumerate(scores):
        if score == max_score:
            result.append(index+1)

    return result

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    ([1, 2, 3, 4, 5], [1]),
    ([1, 3, 2, 4, 2], [1, 2, 3]),

    # 아래는 직접 추가한 경계 케이스
    ([1], [1]),                                          # 문제 하나, 1번만 맞음
    ([2], [2]),                                          # 문제 하나, 2번만 맞음
    ([5], [1, 2, 3]),                                    # 문제 하나, 셋 다 0점
    ([3, 3, 1, 1, 2, 2, 4, 4, 5, 5], [3]),               # 3번 패턴이 한 바퀴
    ([1, 2, 3, 4, 5] * 2000, [1]),                       # 최대 10,000 문제
]

run_tests(solution, test_cases)
