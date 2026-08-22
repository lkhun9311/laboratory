// https://school.programmers.co.kr/learn/courses/30/lessons/42748?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/52_K번째수.py

// Number of times solving questions: 1
// 2026-08-22

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (const vector<int>& command : commands) {
        int i = command[0], j = command[1], k = command[2];
        vector<int> slice(array.begin() + (i-1), array.begin() + j);
        sort(slice.begin(), slice.end());
        answer.push_back(slice[k-1]);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1,5,2,6,3,7,4}, {{2,5,3},{4,4,1},{1,7,3}}), vector<int>{5,6,3});
    t.check("i==j", solution({1,5,2,6,3,7,4}, {{4,4,1}}), vector<int>{6});
    t.check("전체 구간 끝", solution({1,5,2,6,3,7,4}, {{1,7,7}}), vector<int>{7});
    t.check("길이 1", solution({42}, {{1,1,1}}), vector<int>{42});
    return t.report();
}
