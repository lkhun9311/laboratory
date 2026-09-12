# https://school.programmers.co.kr/learn/courses/30/lessons/178871?language=python3

# Number of times solving questions: 1
# 2026-09-12

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(players, callings):
    # 규칙 1. players 는 등수 순서다 (앞이 1등). 호명된 선수는 바로 앞 선수를 추월한다.
    # 규칙 2. 1등은 불리지 않으므로 호명된 선수의 인덱스는 항상 1 이상이다.
    # 규칙 3. 선수 50,000 / 호명 1,000,000. 호명마다 .index() 로 훑으면 O(n*m) 이라 시간 초과.
    #         이름 -> 현재 위치를 O(1)로 알아야 한다.

    position = {player: index for index, player in enumerate(players)}

    for calling in callings:
        i = position[calling]

        players[i - 1], players[i] = players[i], players[i - 1]   # 추월

        # 자리를 바꿨으면 위치표도 같이 고친다. 빠뜨리면 그 뒤가 전부 어긋난다.
        # swap 이 끝난 뒤이므로 players[i-1] 이 호명된 선수, players[i] 가 밀려난 선수다.
        position[players[i - 1]] -= 1
        position[players[i]] += 1

    return players

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["mumu", "soe", "poe", "kai", "mine"], ["kai", "kai", "mine", "mine"]),
     ["mumu", "kai", "mine", "soe", "poe"]),
]

run_tests(solution, test_cases)