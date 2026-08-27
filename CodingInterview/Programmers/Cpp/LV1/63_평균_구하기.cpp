// https://school.programmers.co.kr/learn/courses/30/lessons/12944?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!63_평균_구하기.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
using namespace std;

double solution(vector<int> arr) {
    double arr_size = arr.size();
    double arr_sum = accumulate(arr.begin(), arr.end(), 0);
    return arr_sum / arr_size;
}

int main() {
    Tester t("solution");
    t.check(solution({1, 2, 3, 4}), 2.5);
    t.check(solution({5, 5}), 5.0);
    t.check("길이 1", solution({7}), 7.0);
    t.check("음수 포함", solution({-10000, 10000}), 0.0);
    t.check("최댓값 100개", solution(vector<int>(100, 10000)), 10000.0);
    t.check("나누어떨어지지 않음", solution({1, 2}), 1.5);
    return t.report();
}
