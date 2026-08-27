// https://school.programmers.co.kr/learn/courses/30/lessons/70128?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!44_내적.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    int loop_size = a.size();
    for (int i = 0; i < loop_size; i++) {
        answer += a[i] * b[i];
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1,2,3,4}, {-3,-1,0,2}), 3);
    t.check(solution({-1,0,1}, {1,0,-1}), -2);
    t.check("길이 1", solution({5}, {5}), 25);
    t.check("최댓값 최악", solution(vector<int>(1000, 1000), vector<int>(1000, 1000)), 1000000000);
    t.check("최솟값 최악", solution(vector<int>(1000, -1000), vector<int>(1000, 1000)), -1000000000);
    return t.report();
}
