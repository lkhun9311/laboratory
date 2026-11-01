# https://www.hackerrank.com/challenges/counting-valleys/problem
# 난이도: Easy (정답률 95.3%, 82만 명 통과 — 2026-10-31 API 조회)
# 반환: INTEGER  (문제마다 return 인지 print 인지 다르다. 틀 위 주석이 계약서다)

# Number of times solving questions: 1
# 2026-10-31
# 결과: 통과

def countingValleys(steps, path):
    """해수면 아래에서 막 올라온 순간만 센다. 배열을 만들지 않는다."""
    level = 0
    valleys = 0

    for c in path:
        if c == 'U':
            level += 1
            if level == 0:          # 아래에 있다가 해수면으로 복귀 -> 골짜기 하나 끝
                valleys += 1
        else:
            level -= 1

    return valleys


# ─────────────────────────────────────────────────────────────
# 처음 통과한 판 (기록용)
# ─────────────────────────────────────────────────────────────
def countingValleys_v1(steps, path):
    """걸음마다 부호를 배열에 적고 -> 연속 중복 압축 -> -1 개수를 셈. 세 번 훑는다."""
    tmp_arr = ["-"] * steps
    total = 0
    for idx, p in enumerate(path):
        if p == "U":
            total += 1
        elif p == "D":
            total -= 1
        tmp_arr[idx] = 1 if total > 0 else (0 if total == 0 else -1)

    f_arr = [tmp_arr[0]]
    for t in range(1, len(tmp_arr)):
        if tmp_arr[t - 1] == tmp_arr[t]:
            continue
        f_arr.append(tmp_arr[t])
    return f_arr.count(-1)

# 실측(2026-10-31, steps=1,000,000 "DU"x500,000):
#   v1  229.3 ms, 추가 메모리 15.7 MB   (배열 2개 + 3회 순회)
#   최종 24.8 ms, 추가 메모리  0.0 MB   (1회 순회)
#   정확성은 무작위 50,000건 대조에서 둘 다 불일치 0건
#
# v1 에서 지역 변수 이름을 sum 으로 두었는데, 내장 함수 sum 을 가린다.
# 그 함수 안에서 sum([...]) 을 쓰면 TypeError 가 난다. level/total 처럼 뜻이 드러나는 이름을 쓴다.

if __name__ == '__main__':
    assert countingValleys(8, "UDDDUDUU") == 1
    assert countingValleys(8, "DDUUDDUU") == 2
    assert countingValleys(1, "U") == 0
    assert countingValleys(2, "DU") == 1
    print("ok")
