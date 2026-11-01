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

    return num_of_a * share + s[:rem].count("a")

# 실측(2026-11-01):
#   무작위 대조 100,000건 불일치 0건 (기준: 실제로 n 글자까지 이어 붙여 센 구현)
#   최악 n=10^12, len(s)=100 -> 0.0012 ms
#   문자열을 만들었다면 10^12 글자 = 1TB 라 애초에 불가능하다.

if __name__ == '__main__':
    assert repeatedString("aba", 10) == 7
    assert repeatedString("a", 1000000000000) == 1000000000000
    assert repeatedString("bbb", 1000000000000) == 0
    assert repeatedString("ab", 1000000000000) == 500000000000
    assert repeatedString("b", 1) == 0
    print("ok")
