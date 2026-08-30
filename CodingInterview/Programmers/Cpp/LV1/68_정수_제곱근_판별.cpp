// https://school.programmers.co.kr/learn/courses/30/lessons/12934?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!68_정수_제곱근_판별.py

// Number of times solving questions: 1
// 2026-08-30

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// sqrt 는 double 을 주지만 결과를 즉시 long long 으로 잘라내므로
// 이후 root*root == n 은 정수 비교가 된다.
// 정수 root 에 대해 root*root == n 이면 n 은 정의상 완전제곱수이므로 거짓 양성이 불가능하다.
// (n 최대 5x10^13 < 2^53 이라 sqrt 가 완전제곱수를 놓치는 일도 없음 — 707만개 전수 확인)
bool is_sqrt_int(long long n) {
    long long root = sqrt((double)n);
    if (root*root == n) {
        return true;
    }

    return false;
}

long long solution(long long n) {
    if (is_sqrt_int(n)) {
        long long root = sqrt((double)n);
        return (root+1) * (root+1);
    }

    return -1;
}

int main() {
    Tester t("solution");
    t.check(solution(121), 144LL);
    t.check(solution(3), -1LL);
    t.check("n=1", solution(1), 4LL);
    t.check("정밀도 함정", solution(49999995000000LL), -1LL);
    t.check("최대 완전제곱수", solution(49999988518489LL), 50000002660624LL);
    return t.report();
}
