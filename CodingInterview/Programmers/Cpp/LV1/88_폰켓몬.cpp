// https://school.programmers.co.kr/learn/courses/30/lessons/1845?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/88_폰켓몬.py

// Number of times solving questions: 1
// 2026-08-22

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int take_limit = nums.size() / 2;
    unordered_set<int> kinds(nums.begin(), nums.end());
    int kinds_size = kinds.size();
    return min(take_limit, kinds_size);
}

int main() {
    Tester t("solution");
    t.check(solution({3, 1, 2, 3}), 2);
    t.check(solution({3, 3, 3, 2, 2, 4}), 3);
    t.check(solution({3, 3, 3, 2, 2, 2}), 2);
    t.check("전부 같은 종류", solution(vector<int>(10000, 7)), 1);
    t.check("전부 다른 종류", solution([]{ vector<int> v; for (int i = 1; i <= 10000; i++) v.push_back(i); return v; }()), 5000);
    t.check("최소 길이", solution({1, 1}), 1);
    return t.report();
}
