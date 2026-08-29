# https://school.programmers.co.kr/learn/courses/30/lessons/12950?language=python3

# Number of times solving questions: 1
# 2026-08-29

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(arr1, arr2):
    # 규칙. 같은 크기의 두 행렬을 같은 자리끼리 더한다.
    #      결과를 미리 만들지 않고 한 행씩 완성해 붙이면 크기 계산 실수가 없다.
    answer = []
    arr_row_size = len(arr1)
    arr_col_size = len(arr1[0])

    for i in range(arr_row_size):
        row = []
        for j in range(arr_col_size):
            row.append(arr1[i][j] + arr2[i][j])
        answer.append(row)

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([[1,2],[2,3]], [[3,4],[5,6]]), [[4,6],[7,9]]),
    (([[1],[2]], [[3],[4]]), [[4],[6]]),
    (([[1,2,3]], [[4,5,6]]), [[5,7,9]]),
    (([[1],[2],[3]], [[10],[20],[30]]), [[11],[22],[33]]),
]

run_tests(solution, test_cases)
