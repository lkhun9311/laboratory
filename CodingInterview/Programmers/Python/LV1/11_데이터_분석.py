# https://school.programmers.co.kr/learn/courses/30/lessons/250121?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(data, ext, val_ext, sort_by):
    index = {
        "code": 0,
        "date": 1,
        "maximum": 2,
        "remain": 3
    }

    filtered_data = []
    for d in data:
        if d[index[ext]] < val_ext:
            filtered_data.append(d)

    answer = sorted(filtered_data, key=lambda x: x[index[sort_by]])

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    (([[1, 20300104, 100, 80], [2, 20300804, 847, 37], [3, 20300401, 10, 8]],
      "date", 20300501, "remain"),
     [[3, 20300401, 10, 8], [1, 20300104, 100, 80]]),

    # 아래는 직접 추가한 경계 케이스
    (([[1, 20300104, 100, 80]], "code", 2, "maximum"), [[1, 20300104, 100, 80]]),   # 행 하나, 통과
    (([[1, 20300104, 100, 80]], "code", 1, "maximum"), []),                         # 빈 결과
    (([[5, 20300104, 100, 80]], "code", 5, "code"), []),                            # 경계값은 제외 (< 이므로)
    (([[3, 1, 1, 1], [1, 2, 2, 2], [2, 3, 3, 3]], "maximum", 100, "code"),
     [[1, 2, 2, 2], [2, 3, 3, 3], [3, 1, 1, 1]]),                                   # code 로 정렬
    (([[1, 1, 50, 9], [2, 2, 10, 8], [3, 3, 90, 7]], "remain", 9, "maximum"),
     [[2, 2, 10, 8], [3, 3, 90, 7]]),                                               # 일부만 걸러지고 maximum 정렬
]

run_tests(solution, test_cases)
