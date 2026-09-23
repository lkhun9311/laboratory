# https://school.programmers.co.kr/learn/courses/30/lessons/250137?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-23

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(bandage, health, attacks):
    c_health = health
    skill_time = bandage[0]
    recover_per_time = bandage[1]
    plus_recover = bandage[2]
    recover_time = 0

    time= 0
    attack_idx = 0
    attack_size = len(attacks)
    last_time = attacks[-1][0]

    while time <= last_time:
        attack_time = attacks[attack_idx][0]
        if time == attack_time:
            recover_time = 0
            damage = attacks[attack_idx][1]
            c_health -= damage
            if c_health<=0:
                return -1

            attack_idx += 1
            time += 1
            continue

        c_health += recover_per_time
        recover_time += 1
        if recover_time == skill_time:
            recover_time = 0
            c_health += plus_recover

        c_health = min(c_health, health)

        time += 1

    if c_health<=0:
        c_health = -1
    return c_health

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([5, 1, 5], 30, [[2, 10], [9, 15], [10, 5], [11, 5]]), 5),
    (([3, 2, 7], 20, [[1, 15], [5, 16], [8, 6]]), -1),
    (([4, 2, 7], 20, [[1, 15], [5, 16], [8, 6]]), -1),
    (([1, 1, 1], 5, [[1, 2], [3, 2]]), 3),

    # 아래는 직접 추가한 경계 케이스
    (([1, 1, 1], 5, [[1, 5]]), -1),                       # 첫 공격에 즉사
    (([1, 1, 1], 5, [[1, 4]]), 1),                        # 체력 1 로 생존
    (([2, 1, 3], 10, [[1, 5], [4, 1]]), 9),               # 중간에 보너스 한 번
    (([100, 1, 100], 10, [[1, 5]]), 5),                   # 연속 성공이 한 번도 안 채워짐
]

run_tests(solution, test_cases)
