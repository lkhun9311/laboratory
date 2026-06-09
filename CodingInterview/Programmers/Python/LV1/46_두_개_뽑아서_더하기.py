# Number of times solving questions: 1
# 2026-06-07

# ─────────────────────────────────────────────────────────────
# 풀이 1: 이중 반복문 + set
# ─────────────────────────────────────────────────────────────
# 핵심 아이디어:
#   서로 다른 두 인덱스(i, j)의 모든 쌍을 순회하며 합을 set에 누적
#   → set이 중복된 합을 자동으로 제거해 줌
def solution1(numbers):
    result = set()                                  # 중복 제거 목적으로 set 사용 (문제 요구: "한 번씩만")
    len_of_numbers = len(numbers)                   # 반복문에서 매번 len() 호출하지 않도록 미리 캐싱

    # i < j 조건을 강제하여 (i, j)와 (j, i)를 중복으로 처리하는 것을 방지
    for i in range(len_of_numbers - 1):             # i: 0 ~ n-2
        for j in range(i + 1, len_of_numbers):      # j: i+1 ~ n-1  (항상 i < j)
            sum_of_numbers = numbers[i] + numbers[j]
            result.add(sum_of_numbers)              # set이므로 동일한 합은 한 번만 저장됨

    result = sorted(result)                         # sorted()는 list를 반환 (문제 요구: 오름차순 정렬)
                                                    # ※ list(sorted(...))는 중복이라 sorted()만으로 충분
    return result


# ─────────────────────────────────────────────────────────────
# 풀이 2: itertools.combinations + set comprehension
# ─────────────────────────────────────────────────────────────
# 핵심 아이디어:
#   combinations(numbers, 2)가 "서로 다른 두 원소의 쌍"을 C 구현으로 생성
#   → 파이썬 이중 for문보다 빠르고, 인덱스 관리도 불필요해 가독성도 좋음
from itertools import combinations

def solution2(numbers):
    # 분해 설명:
    #   combinations(numbers, 2) → (a, b) 쌍을 차례로 yield (이미 i<j 조건 보장)
    #   {a + b for ...}          → set comprehension으로 합을 모으며 중복 제거
    #   sorted(...)              → set을 오름차순 정렬된 list로 변환
    return sorted({a + b for a, b in combinations(numbers, 2)})


# ─────────────────────────────────────────────────────────────
# 복잡도 분석
# ─────────────────────────────────────────────────────────────
# 시간: 두 풀이 모두 O(n²) — 모든 쌍(nC2)을 확인해야 하므로 이론적 하한
# 공간: O(n²) — 최악의 경우 모든 합이 서로 달라 set 크기가 nC2까지 증가
# 실측: 문제 제약(2 ≤ n ≤ 100)에서는 둘 다 즉시 통과
#       단, solution2가 C-level 구현 덕분에 상수배 더 빠름

# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ([2, 1, 3, 4, 1], [2, 3, 4, 5, 6, 7]),
    ([5, 0, 2, 7],    [2, 5, 7, 9, 12]),
]

for nums, expected in test_cases:
    print(f"입력: {nums}  | 기대값: {expected}")
    print(f"  solution1 → {solution1(nums)}")
    print(f"  solution2 → {solution2(nums)}")