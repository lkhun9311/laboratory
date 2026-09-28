# https://school.programmers.co.kr/learn/courses/30/lessons/150370?language=python3
# 출처: 2023 KAKAO BLIND RECRUITMENT

# Number of times solving questions: 1
# 2026-09-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(today, terms, privacies):
    answer = []
    terms_dict = {}
    for term in terms:
        t_key, t_value = term.split(" ")
        terms_dict[t_key] = t_value

    t_y, t_m, t_d = today.split(".")
    t_days = int(t_y)*28*12 + int(t_m)*28 + int(t_d)
    index = 1
    for privacy in privacies:
        p_date, p_term = privacy.split(" ")
        p_y, p_m, p_d = p_date.split(".")
        p_days = int(p_y)*28*12 + int(p_m)*28 + int(p_d)
        p_days += int(terms_dict[p_term])*28

        if t_days >= p_days:
            answer.append(index)
        index += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 이 문제에서 모든 달은 28일이므로 날짜는 1~28 만 존재한다.
# (2026-09-16 C++ 풀이 때 31 일짜리 입력을 만들어 넣었다가 헛된 실패를 본 적이 있다)
test_cases = [
    (("2022.05.19", ["A 6", "B 12", "C 3"],
      ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]), [1, 3]),
    (("2020.01.01", ["Z 3", "D 5"],
      ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]), [1, 4, 5]),

    # 아래는 직접 추가한 경계 케이스
    (("2022.01.28", ["A 1"], ["2022.01.01 A"]), []),            # 유효기간 마지막 날 — 아직 유효
    (("2022.01.29", ["A 1"], ["2022.01.01 A"]), [1]),           # 하루 지나면 파기
    (("2022.01.01", ["A 1"], ["2022.01.01 A"]), []),            # 같은 날 수집, 기간 1달
    (("2030.12.28", ["A 1", "B 1"], ["2000.01.01 A", "2000.01.01 B"]), [1, 2]),   # 전부 파기
    (("2023.01.01", ["A 12"], ["2021.12.28 A"]), [1]),          # 연도가 넘어간다
]

run_tests(solution, test_cases)
