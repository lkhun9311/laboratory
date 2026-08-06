# https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=python3

# Number of times solving questions: 1
# 2026-08-06

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(id_list, report, k):
    answer = [0] * len(id_list)

    # 이름 → id_list에서의 위치. 미리 만들어두면 조회가 O(1) (list.index는 매번 O(N))
    user_index = {user: index for index, user in enumerate(id_list)}

    # 신고당한 사람을 키로, 그를 신고한 사람들의 집합을 값으로 둔다
    reporters_by_user = {user: set() for user in id_list}

    # set이라 같은 사람이 같은 사람을 여러 번 신고해도 1회로 처리된다
    for entry in report:
        reporter, reported_user = entry.split()
        reporters_by_user[reported_user].add(reporter)

    # k번 이상 신고당한 유저가 정지되면, 정지된 유저 본인이 아니라 신고자들이 메일을 받는다
    for reported_user, reporters in reporters_by_user.items():
        if len(reporters) >= k:
            for reporter in reporters:
                answer[user_index[reporter]] += 1

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["muzi", "frodo", "apeach", "neo"],
      ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"],
      2), [2, 1, 1, 0]),
    ((["con", "ryan"],
      ["ryan con", "ryan con", "ryan con", "ryan con"],
      3), [0, 0]),
]

run_tests(solution, test_cases)