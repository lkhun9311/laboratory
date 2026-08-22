// https://school.programmers.co.kr/learn/courses/30/lessons/12912?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/83_두_정수_사이의_합.py

// Number of times solving questions: 1
// 2026-08-22

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    long long start = min(a, b);
    long long end = max(a, b);

    answer = (end - start + 1) * (start + end) / 2;

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(3, 5), 12LL);
    t.check(solution(3, 3), 3LL);
    t.check(solution(5, 3), 12LL);
    t.check("최대 범위", solution(-10000000, 10000000), 0LL);
    t.check("양수 최대", solution(1, 10000000), 50000005000000LL);
    t.check("음수 최대", solution(-10000000, -1), -50000005000000LL);
    t.check("a > b 큰 폭", solution(10000000, -10000000), 0LL);
    return t.report();
}
