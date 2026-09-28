# https://school.programmers.co.kr/learn/courses/30/lessons/17681?language=python3
# 출처: 2018 KAKAO BLIND RECRUITMENT

# Number of times solving questions: 1
# 2026-09-28

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

def solution(n, arr1, arr2):
    answer = []

    for el1, el2 in zip(arr1, arr2):
        bin1 = bin(el1)[2:].zfill(n)
        bin2 = bin(el2)[2:].zfill(n)
        tmp_arr = []
        for i in range(n):
            if bin1[i] == "1" or bin2[i] == "1":
                tmp_arr.append("#")
            else:
                tmp_arr.append(" ")
        answer.append("".join(tmp_arr))

    return answer

# 왼쪽을 채우는 방법들 (2026-09-28 정리)
#   bin1.zfill(n)            0 으로 채운다
#   bin1.rjust(n, "0")       원하는 문자로 왼쪽을 채운다
#   bin1.ljust(n, "0")       오른쪽을 채운다
#   (n-len(bin1))*"0" + bin1 직접 이어 붙인다
#   format(el1, f"0{n}b")    변환과 채우기를 한 번에 한다

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
# 아래 기대값은 2026-09-16 에 같은 문제를 C++ 로 풀 때 쓴 것과 같다
test_cases = [
    ((5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]),
     ["#####", "# # #", "### #", "#  ##", "#####"]),
    ((6, [46, 33, 33, 22, 31, 50], [27, 56, 19, 14, 14, 10]),
     ["######", "###  #", "##  ##", " #### ", " #####", "### # "]),

    # 아래는 직접 추가한 경계 케이스
    ((1, [0], [0]), [" "]),                                  # 최소 n, 벽 없음
    ((1, [1], [0]), ["#"]),                                  # 최소 n, 벽 있음
    ((5, [0, 0, 0, 0, 1], [0, 0, 0, 0, 0]),
     ["     ", "     ", "     ", "     ", "    #"]),         # 앞자리 0 이 공백으로 남는다
    ((16, [65535] * 16, [0] * 16), ["#" * 16] * 16),         # 최대 n, 전부 벽
    ((16, [32768] * 16, [0] * 16), ["#" + " " * 15] * 16),   # 최대 n, 맨 왼쪽 비트만
]

run_tests(solution, test_cases)
