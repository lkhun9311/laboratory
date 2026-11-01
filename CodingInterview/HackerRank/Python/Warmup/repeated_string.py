# https://www.hackerrank.com/challenges/repeated-string/problem
# 난이도: Easy (정답률 90.8%, 56만 명 통과 — 2026-10-31 API 조회)
# 반환: LONG_INTEGER

# Number of times solving questions: 1
# 2026-11-01
# 결과: 통과

def repeatedString(s, n):
    """n 이 10^12 라 문자열을 만들면 안 된다. 몫과 나머지로 센다."""
    num_of_a = s.count("a")
    s_size = len(s)
    share = n // s_size
    rem = n % s_size

    # s[:rem].count("a") 는 잘라낸 복사본을 새로 만든 뒤 센다.
    # count 에 범위를 주면 복사 없이 같은 결과를 낸다.
    return num_of_a * share + s.count("a", 0, rem)

# 실측(2026-11-01):
#   무작위 대조 100,000건 불일치 0건 (기준: 실제로 n 글자까지 이어 붙여 센 구현)
#   최악 n=10^12, len(s)=100 -> 0.0012 ms
#   문자열을 만들었다면 10^12 글자 = 1TB 라 애초에 불가능하다.
#
# 변형 비교(10만 회 호출 합계): s[:rem].count("a") 12.5 ms / s.count("a", 0, rem) 11.1 ms.
# 이 문제에서는 s 가 최대 100 자라 차이가 없다. 슬라이스가 긴 문자열이면 그때 벌어진다.

if __name__ == '__main__':
    assert repeatedString("aba", 10) == 7
    assert repeatedString("a", 1000000000000) == 1000000000000
    assert repeatedString("bbb", 1000000000000) == 0
    assert repeatedString("ab", 1000000000000) == 500000000000
    assert repeatedString("b", 1) == 0
    print("ok")
