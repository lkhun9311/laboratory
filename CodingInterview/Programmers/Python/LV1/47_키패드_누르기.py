# https://school.programmers.co.kr/learn/courses/30/lessons/67256?language=python3
# 출처: 2020 카카오 인턴십

# Number of times solving questions: 1
# 2026-09-30

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(numbers, hand):
    answer = ''

    left_h = (3,0)
    right_h = (3,2)

    pos = {
        1: (0,0), 2: (0,1), 3: (0,2),
        4: (1,0), 5: (1,1), 6: (1,2),
        7: (2,0), 8: (2,1), 9: (2,2),
                  0: (3,1)
    }

    for number in numbers:
        if number in [1, 4, 7]:
            left_h = pos[number]
            answer += "L"
        elif number in [3, 6, 9]:
            right_h = pos[number]
            answer += "R"
        else:
            number_pos = pos[number]
            left_length = abs(left_h[0] - number_pos[0]) + abs(left_h[1] - number_pos[1])
            right_length = abs(right_h[0] - number_pos[0]) + abs(right_h[1] - number_pos[1])

            if left_length > right_length:
                right_h = pos[number]
                answer += "R"
            elif left_length < right_length:
                left_h = pos[number]
                answer += "L"
            else:
                if hand == "right":
                    right_h = pos[number]
                    answer += "R"
                elif hand == "left":
                    left_h = pos[number]
                    answer += "L"

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"), "LRLLLRLLRRL"),
    (([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], "left"), "LRLLRRLLLRR"),
    (([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], "right"), "LLRLLRLLRL"),

    # 아래는 직접 추가한 경계 케이스
    (([1], "right"), "L"),                    # 왼쪽 열은 항상 왼손
    (([3], "left"), "R"),                     # 오른쪽 열은 항상 오른손
    (([2], "left"), "L"),                     # 시작 거리가 같다 (왼손 주력)
    (([2], "right"), "R"),                    # 시작 거리가 같다 (오른손 주력)
    (([0], "left"), "L"),                     # 0 도 시작 거리가 같다
    (([0], "right"), "R"),
    (([1, 2], "right"), "LL"),                # 1 을 누른 왼손이 2 에 더 가깝다
    (([3, 2], "left"), "RR"),                 # 3 을 누른 오른손이 2 에 더 가깝다
]

run_tests(solution, test_cases)
