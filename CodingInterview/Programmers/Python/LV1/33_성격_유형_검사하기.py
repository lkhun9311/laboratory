# https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=python3
# 출처: 2022 KAKAO TECH INTERNSHIP

# Number of times solving questions: 1
# 2026-09-27

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(survey, choices):
    answer = ''
    survey_to_score = { ch: 0 for ch in "RTCFJMAN" }

    for s, choice in zip(survey, choices):
        if choice < 4:
            survey_to_score[s[0]] += 4 - choice

        if choice > 4:
            survey_to_score[s[1]] += choice - 4

    for a, b in ("RT", "CF", "JM", "AN"):
        if survey_to_score[a] >= survey_to_score[b]:
            answer += a
        else:
            answer += b

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    ((["AN", "CF", "MJ", "RT", "NA"], [5, 3, 2, 7, 5]), "TCMA"),
    ((["TR", "RT", "TR"], [7, 1, 3]), "RCJA"),

    # 아래는 직접 추가한 경계 케이스
    ((["AN", "CF", "MJ", "RT"], [4, 4, 4, 4]), "RCJA"),      # 모두 '모름' — 전부 동점이라 앞 글자
    ((["NA"], [7]), "RCJA"),                                  # 질문 하나
    ((["RT", "CF", "JM", "AN"], [7, 7, 7, 7]), "TFMN"),       # 뒤 글자만 이긴다
    ((["RT", "CF", "JM", "AN"], [1, 1, 1, 1]), "RCJA"),       # 앞 글자만 이긴다
    ((["RT", "TR"], [1, 1]), "RCJA"),                         # 같은 지표가 서로 상쇄돼 동점
]

run_tests(solution, test_cases)
