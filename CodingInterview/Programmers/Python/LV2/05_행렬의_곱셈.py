# https://school.programmers.co.kr/learn/courses/30/lessons/12949?language=python3
# 유형: 구현

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(arr1, arr2):
    # 규칙 1. 결과의 (i, j) 자리는 arr1 의 i번째 "행" 과 arr2 의 j번째 "열" 을
    #         앞에서부터 짝지어 곱한 뒤 전부 더한 값이다.
    # 규칙 2. 곱할 수 있는 형태만 주어진다 = arr1 의 열 수와 arr2 의 행 수가 같다.

    # 세 크기에 이름을 붙여 둔다. 삼중 루프에서 i, j, k 가 어느 행렬의 무엇인지
    # 헷갈리는 것이 이 문제의 유일한 난관이기 때문이다.
    row = len(arr1)         # 결과의 행 수 = arr1 의 행 수
    mid = len(arr2)         # 짝지어 곱하는 횟수 (len(arr1[0]) 와 같다 - 규칙 2)
    col = len(arr2[0])      # 결과의 열 수 = arr2 의 열 수

    # [[0]*col]*row 는 같은 행을 공유해 망가진다. 컴프리헨션으로 매번 새로 만든다.
    answer = [[0]*col for _ in range(row)]

    # k 가 arr1 에서는 "열", arr2 에서는 "행" 으로 쓰이는 것이 행렬 곱의 정의 그 자체다. (규칙 1)
    for i in range(row):
        for j in range(col):
            for k in range(mid):
                answer[i][j] += arr1[i][k] * arr2[k][j]

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([[1, 4], [3, 2], [4, 1]],
      [[3, 3], [3, 3]]),
     [[15, 15], [15, 15], [15, 15]]),
    (([[2, 3, 2], [4, 2, 4], [3, 1, 4]],
      [[5, 4, 3], [2, 4, 1], [3, 1, 1]]),
     [[22, 22, 11], [36, 28, 18], [29, 20, 14]]),
]

run_tests(solution, test_cases)
