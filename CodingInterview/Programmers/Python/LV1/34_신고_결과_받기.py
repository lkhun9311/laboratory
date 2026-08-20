# https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=python3

# Number of times solving questions: 2
# 2026-08-20

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(id_list, report, k):
    # 규칙 1. 한 유저는 여러 명을 신고할 수 있다. 단 같은 유저를 여러 번 신고해도 1회로 친다.
    # 규칙 2. k번 이상 신고당한 유저는 정지되고, 메일은 정지된 본인이 아니라 그를 신고한 사람들이 받는다.

    # 1. 신고 기록을 "신고당한 사람 -> 그를 신고한 사람들" 방향으로 뒤집어 모은다.
    #    값이 set이라 같은 사람의 중복 신고는 저절로 1회로 합쳐진다. (규칙 1)
    reporters_by_suspect = { user: set() for user in id_list }

    for report_record in report:
        reporter, suspect = report_record.split()
        reporters_by_suspect[suspect].add(reporter)

    # 2. 신고자가 k명 이상이면 그 유저는 정지.
    #    정지가 확정되는 순간 그를 신고한 사람들의 메일 수를 한꺼번에 올린다. (규칙 2)
    emails = { user: 0 for user in id_list }

    for reporters in reporters_by_suspect.values():
        if len(reporters) >= k:
            for reporter in reporters:
                emails[reporter] += 1

    # 3. emails를 id_list 순서로 만들어 두었으므로, 값만 꺼내면 그대로 정답 순서가 된다.
    return list(emails.values())

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