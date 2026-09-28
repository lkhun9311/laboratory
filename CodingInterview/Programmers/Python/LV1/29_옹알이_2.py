# https://school.programmers.co.kr/learn/courses/30/lessons/133499?language=python3
# 출처: 연습문제

# Number of times solving questions: 1
# 2026-09-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(babbling):
    answer = 0
    pro_set = {"aya", "ye", "woo", "ma"}

    for bab in babbling:
        tmp_bab = ""
        pre_bab = ""

        for b in bab:
            tmp_bab += b

            if tmp_bab in pro_set:
                if tmp_bab == pre_bab:
                    break

                pre_bab = tmp_bab
                tmp_bab = ""

        if not tmp_bab:
            answer += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    (["aya", "yee", "u", "maa", "wyeoo"], 1),
    (["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"], 2),

    # 아래는 직접 추가한 경계 케이스
    (["aya"], 1),                    # 한 단어
    (["yeye"], 0),                   # 같은 말을 연속 — 불가
    (["ayaya"], 0),                  # aya 뒤에 ya 가 남는다
    (["mayewoo"], 1),                # ma + ye + woo
    (["woowoo"], 0),                 # 같은 말 연속
    (["woomawoo"], 1),               # 사이에 다른 말이 끼면 가능
    (["a"], 0),                      # 어떤 말도 못 만든다
    (["yeayamawoo"], 1),             # ye + aya + ma + woo
]

run_tests(solution, test_cases)
