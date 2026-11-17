# https://school.programmers.co.kr/learn/courses/30/lessons/340213?language=python3

# Number of times solving questions: 1
# 2026-11-17

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def cal_time(time):
    mm, ss = map(int, time.split(":"))
    return mm*60 + ss

def skip_openging(real_pos, real_op_start, real_op_end):
    if real_op_start <= real_pos <= real_op_end:
        return real_op_end
    return real_pos

def solution(video_len, pos, op_start, op_end, commands):
    real_video_len = cal_time(video_len)
    real_pos = cal_time(pos)
    real_op_start = cal_time(op_start)
    real_op_end =  cal_time(op_end)

    real_pos = skip_openging(real_pos, real_op_start, real_op_end)

    for command in commands:
        if command == "prev":
            real_pos = max(0, real_pos-10)
        elif command == "next":
            real_pos = min(real_video_len, real_pos+10)

        real_pos = skip_openging(real_pos, real_op_start, real_op_end)

    miniute = real_pos // 60
    second = real_pos % 60
    return f"{miniute:02d}:{second:02d}"

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (("34:33", "13:00", "00:55", "02:55", ["next", "prev"]), "13:00"),
    (("10:55", "00:05", "00:15", "06:55", ["prev", "next", "next"]), "06:55"),
    (("07:22", "04:05", "00:15", "04:07", ["next"]), "04:17"),
]

run_tests(solution, test_cases)