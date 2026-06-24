# https://school.programmers.co.kr/learn/courses/30/lessons/76501?language=python3

# Number of times solving questions: 0
# 2026-00-00

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

# ─────────────────────────────────────────────────────────────
# 문제 규칙
# ─────────────────────────────────────────────────────────────
#   정수의 절댓값 배열 absolutes와 부호 배열 signs가 주어진다.
#   - signs[i]가 True면 absolutes[i]는 양수, False면 음수다.
#   - 모든 수를 실제 부호로 복원해 더한 값을 반환한다.
#   - 예) absolutes=[4,7,12], signs=[T,F,T] → 4 - 7 + 12 = 9

# ─────────────────────────────────────────────────────────────
# 풀이: 부호에 따라 ± 누적
# ─────────────────────────────────────────────────────────────
# 핵심 아이디어:
#   인덱스를 돌며 signs[i]가 참이면 더하고, 거짓이면 뺀다.
#   (불리언은 `== True` 비교 없이 `if signs[i]:`로 바로 판정한다.)
def solution(absolutes, signs):
    result = 0
    len_signs = len(signs)

    for i in range(len_signs):
        if signs[i]:               # 양수면 더하고
            result += absolutes[i]
        else:                      # 음수면 뺀다
            result -= absolutes[i]

    return result

# 더 파이썬다운 대안 (인덱스 없이 두 배열을 짝지어 합산):
#   def solution(absolutes, signs):
#       return sum(a if s else -a for a, s in zip(absolutes, signs))
#   → zip으로 (절댓값, 부호) 쌍을 동시 순회 + 삼항으로 부호 적용 + sum 한 번에.

# ─────────────────────────────────────────────────────────────
# 복잡도 분석
# ─────────────────────────────────────────────────────────────
# 시간: O(n) — 모든 원소를 한 번씩 더하는 게 하한
# 공간: O(1) — 누적 변수만 사용
# 결론: 이미 최적 복잡도. 차이는 성능이 아니라 "표현"의 영역.

# ─────────────────────────────────────────────────────────────
# 이 문제에서 배운 것 (Takeaways)
# ─────────────────────────────────────────────────────────────
#   1. 두 시퀀스를 동시에 돌 땐 range(len())+인덱싱보다 zip이 정석이다.
#   2. 불리언은 `if x == True`가 아니라 `if x:`로 바로 판정한다(안티패턴 회피).
#   3. "부호 적용 후 합산"은 sum(a if s else -a for ...)로 한 줄에 표현 가능.

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([4, 7, 12], [True, False, True]), 9),
    (([1, 2, 3], [False, False, True]), 0),
]

run_tests(solution, test_cases)