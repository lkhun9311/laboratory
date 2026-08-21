# https://school.programmers.co.kr/learn/courses/30/lessons/42576?language=python3

# Number of times solving questions: 1
# 2026-08-21

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(participant, completion):
    # 규칙 1. 단 한 명을 제외한 모든 선수가 완주했다. 그러므로 정답은 항상 정확히 한 명이다.
    # 규칙 2. 동명이인이 있을 수 있다. 이름이 같아도 서로 다른 사람이므로
    #        "명단에 있느냐"가 아니라 "몇 명이냐"를 봐야 한다.

    # 1. 참가자를 이름별로 몇 명인지 센다.
    #    .get(player, 0)이 "처음 보는 이름은 0부터"를 맡아주므로 칸을 미리 만들 필요가 없다. (규칙 2)
    count_by_player = {}
    for player in participant:
        count_by_player[player] = count_by_player.get(player, 0) + 1

    # 2. 완주자를 한 명씩 읽어 그 이름의 인원을 깎는다.
    #    참가자 쪽이 아니라 completion을 기준으로 도는 것이 핵심이다.
    #    같은 이름이 완주자 명단에 두 번 있으면 두 번 깎여야 하기 때문. (규칙 2)
    for player in completion:
        count_by_player[player] -= 1

    # 3. 다 깎고도 인원이 남은 이름이 완주하지 못한 선수다.
    #    그런 이름은 하나뿐이므로 찾는 즉시 반환한다. (규칙 1)
    for player, count in count_by_player.items():
        if count != 0:
            return player

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["leo", "kiki", "eden"], ["eden", "kiki"]), "leo"),
    ((["marina", "josipa", "nikola", "vinko", "filipa"],
      ["josipa", "filipa", "marina", "nikola"]), "vinko"),
    ((["mislav", "stanko", "mislav", "ana"],
      ["stanko", "ana", "mislav"]), "mislav"),
]

run_tests(solution, test_cases)