# https://school.programmers.co.kr/learn/courses/30/lessons/160586?language=python3

# Number of times solving questions: 1
# 2026-09-13

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(keymap, targets):
    # 규칙 1. keymap[i] 의 j번째 문자는 그 키를 j+1 번 눌러야 나온다.
    # 규칙 2. 같은 문자가 여러 키에 있으면 가장 적게 누르는 쪽을 쓴다.
    # 규칙 3. 어느 키에도 없는 문자가 하나라도 있으면 그 문자열은 -1.

    answer = []

    # 문자 -> 최소 누름 횟수. 미리 만들어 두지 않으면 문자마다 keymap 전체를 다시 훑어야 한다.
    keymap_dict = {}

    for keys in keymap:
        for idx, key in enumerate(keys):
            if key not in keymap_dict:
                keymap_dict[key] = idx + 1
            else:
                keymap_dict[key] = min(idx + 1, keymap_dict[key])   # (규칙 2)

    for target in targets:
        tmp_result = 0
        for t in target:
            if t not in keymap_dict:        # 없는 문자를 만나면 나머지를 볼 필요가 없다 (규칙 3)
                tmp_result = -1
                break
            tmp_result += keymap_dict[t]
        answer.append(tmp_result)

    return answer

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((["ABACD", "BCEFD"], ["ABCD", "AABB"]), [9, 4]),
    ((["AA"], ["B"]), [-1]),
    ((["AGZ", "BSSS"], ["ASA", "BGZ"]), [4, 6]),
]

run_tests(solution, test_cases)