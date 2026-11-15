# https://school.programmers.co.kr/learn/courses/30/lessons/258712?language=python3
# 출처: 2024 KAKAO WINTER INTERNSHIP

# Number of times solving questions: 1
# 2026-11-15

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(friends, gifts):
    # 모든 쌍을 0으로 미리 채워 두어 주고받은 적 없는 쌍도 KeyError 없이 0으로 읽힌다
    gift_map = {
        friend: {other: 0 for other in friends}
        for friend in friends
    }
    gift_index = {friend: 0 for friend in friends}  # 준 개수 - 받은 개수
    gift_next = {friend: 0 for friend in friends}   # 다음 달에 받을 선물 수

    # 기록을 한 번 훑으면서 쌍별 횟수와 선물 지수를 함께 갱신한다
    for gift in gifts:
        giver, taker = gift.split(" ")
        gift_map[giver][taker] += 1
        gift_index[giver] += 1
        gift_index[taker] -= 1

    # j 를 i+1 부터 시작해 각 쌍을 한 번만 판정한다
    friends_size = len(friends)
    for i in range(friends_size):
        for j in range(i + 1, friends_size):
            A = friends[i]
            B = friends[j]

            gift_A = gift_map[A][B]
            gift_B = gift_map[B][A]

            # 주고받은 기록이 없는 경우(0 == 0)도 "같다"에 포함된다
            if gift_A == gift_B:
                if gift_index[A] > gift_index[B]:
                    gift_next[A] += 1
                elif gift_index[A] < gift_index[B]:
                    gift_next[B] += 1
            elif gift_A > gift_B:
                gift_next[A] += 1
            else:
                gift_next[B] += 1

    return max(gift_next.values())

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"]), 2),
    ((["joy", "brad", "alessandro", "conan", "david"], ["alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david"]), 4),
    ((["a", "b", "c"], ["a b", "b a", "c a", "a c", "a c", "c a"]), 0),
]

run_tests(solution, test_cases)