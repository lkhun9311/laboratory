# https://school.programmers.co.kr/learn/courses/30/lessons/159994?language=python3

# Number of times solving questions: 1
# 2026-09-07

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(cards1, cards2, goal):
    # 규칙 1. 카드는 뭉치의 맨 위에서만 뽑는다. 건너뛰거나 버릴 수 없다.
    #         따라서 실제로 쓰이는 카드는 언제나 뭉치의 "앞에서부터 이어진 구간"이다.
    # 규칙 2. 뭉치를 끝까지 다 쓸 필요는 없다. goal을 채우면 나머지는 남겨도 된다.
    # 규칙 3. cards1과 cards2에는 서로 다른 단어만 존재한다.
    #         이 한 줄이 난이도를 결정한다 — 어떤 단어를 지금 낼 수 있는 뭉치는 많아야 하나뿐이라
    #         "어느 쪽에서 뽑을까" 하는 갈림길이 아예 생기지 않는다.
    #         (같은 단어가 양쪽에 있을 수 있었다면 되돌아가 다시 고르는 백트래킹이 필요해진다.)

    # 뭉치를 실제로 깎지 않고 맨 위가 몇 번째인지만 기억한다.
    # 리스트를 변형하지 않으므로 순회 중 변형 함정이 없고, C++ 재구현에도 그대로 옮겨진다. (규칙 1)
    cards1_top = 0
    cards2_top = 0

    # goal을 앞에서부터 한 단어씩 확정한다. 선택지가 없으므로 (규칙 3)
    # 되돌아가지 않고 한 번의 순회로 판정이 끝난다.
    for word in goal:
        # 뭉치가 바닥나면 맨 위 카드라는 게 존재하지 않는다.
        # and는 왼쪽이 거짓이면 오른쪽을 평가하지 않으므로, 범위 검사를 왼쪽에 두어 IndexError를 막는다. (규칙 2)
        if cards1_top < len(cards1) and cards1[cards1_top] == word:
            cards1_top += 1
        elif cards2_top < len(cards2) and cards2[cards2_top] == word:
            cards2_top += 1
        else:
            # 두 맨 위 카드 어느 쪽도 아니면 이 단어는 영영 나올 수 없다.
            # 이 단어를 덮고 있는 카드를 치울 방법이 없기 때문이다. (규칙 1)
            return "No"

    return "Yes"

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["i", "drink", "water"], ["want", "to"], ["i", "want", "to", "drink", "water"]), "Yes"),
    ((["i", "water", "drink"], ["want", "to"], ["i", "want", "to", "drink", "water"]), "No"),

    # 아래는 직접 추가한 경계 케이스
    ((["a", "b"], ["c", "d"], ["b", "c"]), "No"),   # 맨 위 "a"를 치울 수 없어 "b"에 닿지 못함
    ((["a"], ["b"], ["a", "b"]), "Yes"),            # 뭉치를 다 써서 맨 위가 없어지는 경우
    ((["a", "b"], ["c", "d"], ["a", "c"]), "Yes"),  # 양쪽 모두 일부만 쓰고 끝내도 된다
    ((["a", "b"], ["c", "d"], ["a", "d"]), "No"),   # cards2의 "c"를 건너뛸 수 없음
]

run_tests(solution, test_cases)
