# https://school.programmers.co.kr/learn/courses/30/lessons/136798?language=python3

# Number of times solving questions: 1
# 2026-09-13

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(number, limit, power):
    # 규칙 1. i번 기사의 공격력 = i의 약수 개수.
    # 규칙 2. 공격력이 limit 을 넘으면 power 로 대체한다.
    # 규칙 3. number 최대 100,000 이라 각 수마다 1..i 를 전부 나눠보면 불가능하다.

    result = 0

    for i in range(1, number + 1):
        count = 0
        d = 1

        # i = d * (i/d) 이므로 약수는 쌍으로 나오고, 작은 쪽은 반드시 sqrt(i) 이하다. (규칙 3)
        while d * d <= i:
            if i % d == 0:
                count += 1 if d * d == i else 2     # 완전제곱수는 짝이 자기 자신
            d += 1

        result += power if count > limit else count     # (규칙 2)

    return result

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((5, 3, 2), 10),
    ((10, 3, 2), 21),
]

run_tests(solution, test_cases)