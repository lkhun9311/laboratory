# https://school.programmers.co.kr/learn/courses/30/lessons/77884?language=python3

# Number of times solving questions: 1
# 2026-08-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def count_divisors(number):
    count = 0
    for divisor in range(1, number+1):
        if number%divisor == 0:
            count += 1
    return count


def solution(left, right):
    # 규칙. left~right 의 각 수에 대해, 약수 개수가 짝수면 그 수를 더하고 홀수면 뺀다.
    #      더하고 빼는 대상은 "약수의 개수"가 아니라 "그 수 자체"다.
    #      (약수 개수가 홀수인 수는 완전제곱수뿐이다. 약수는 짝을 이루는데
    #       완전제곱수만 sqrt 가 자기 자신과 짝이 되어 하나로 세지기 때문)
    answer = 0

    for number in range(left, right+1):
        count = count_divisors(number)
        if count%2 == 0:
            answer += number
        else:
            answer -= number

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((13, 17), 43),
    ((24, 27), 52),
    ((1, 1), -1),
    ((1, 10), 27),
    ((1, 1000), 479668),
    ((1000, 1000), 1000),
    ((999, 1000), 1999),
]

run_tests(solution, test_cases)
