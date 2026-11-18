# https://school.programmers.co.kr/learn/courses/30/lessons/388351?language=python3

# Number of times solving questions: 1
# 2026-11-18

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(schedules, timelogs, startday):
    answer = 0
    to_min = lambda t: (t//100)*60 + t%100

    for schedule, timelog in zip(schedules, timelogs):
        if startday != 7:
            new_timelog = timelog[:6-startday] + timelog[8-startday:]
        else:
            new_timelog = timelog[1:-1]

        if all(to_min(t) <= to_min(schedule)+10 for t in new_timelog):
            answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (([700, 800, 1100], [[710, 2359, 1050, 700, 650, 631, 659], [800, 801, 805, 800, 759, 810, 809], [1105, 1001, 1002, 600, 1059, 1001, 1100]], 5), 3),
    (([730, 855, 700, 720], [[710, 700, 650, 735, 700, 931, 912], [908, 901, 805, 815, 800, 831, 835], [705, 701, 702, 705, 710, 710, 711], [707, 731, 859, 913, 934, 931, 905]], 1), 2),
]

run_tests(solution, test_cases)