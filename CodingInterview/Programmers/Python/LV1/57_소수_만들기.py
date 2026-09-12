# https://school.programmers.co.kr/learn/courses/30/lessons/12977?language=python3

# Number of times solving questions: 1
# 2026-09-12

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(nums):
    # 규칙 1. nums 에서 서로 다른 3개를 골라 더한 값이 소수인 경우의 수.
    # 규칙 2. 길이 3~50 이라 C(50,3) = 19,600. 삼중 루프로 충분하다.

    answer = 0
    n = len(nums)

    # j 는 i+1, k 는 j+1 부터 — 같은 조합을 순서만 바꿔 다시 세지 않기 위해서다.
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                total = nums[i] + nums[j] + nums[k]

                # total = a * b 라면 둘 중 하나는 반드시 sqrt(total) 이하이므로
                # sqrt 까지만 훑으면 된다. O(total) -> O(sqrt(total)).
                # 범위 끝을 int(sqrt)+1 로 잡아야 완전제곱수(9, 25 ...)의 제곱근을 검사한다.
                is_prime = True
                for divisor in range(2, int(total ** 0.5) + 1):
                    if total % divisor == 0:
                        is_prime = False
                        break

                if is_prime:
                    answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([1, 2, 3, 4], 1),
    ([1, 2, 7, 6, 4], 4),
]

run_tests(solution, test_cases)