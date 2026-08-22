// https://school.programmers.co.kr/learn/courses/30/lessons/12931
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/71_자릿수_더하기.py

// Number of times solving questions: 1
// 2026-08-22

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(int n)
{
    int answer = 0;

    while (n > 0) {
        answer += n % 10;
        n = n / 10;
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(123), 6);
    t.check(solution(987), 24);
    t.check(solution(1), 1);
    t.check(solution(10), 1);
    t.check(solution(1000), 1);
    t.check("최댓값 10,000,000", solution(10000000), 1);
    t.check("9만 반복", solution(9999999), 63);
    return t.report();
}
