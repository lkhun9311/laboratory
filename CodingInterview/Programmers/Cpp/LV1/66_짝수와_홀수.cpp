// https://school.programmers.co.kr/learn/courses/30/lessons/12937?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/66_짝수와_홀수.py

// Number of times solving questions: 1
// 2026-08-22

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string solution(int num) {
    string answer = "Odd";
    if (num % 2 == 0) {
        answer = "Even";
    }
    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(100), "Even");
    t.check(solution(3), "Odd");
    return t.report();
}
