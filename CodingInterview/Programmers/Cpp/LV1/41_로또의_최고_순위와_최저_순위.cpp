// https://school.programmers.co.kr/learn/courses/30/lessons/77484?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!41_로또의_최고_순위와_최저_순위.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int number_of_0 = count(lottos.begin(), lottos.end(), 0);
    int base_result = 0;
    unordered_map<int, int> ranks = {
        {6, 1},
        {5, 2},
        {4, 3},
        {3, 4},
        {2, 5},
        {1, 6},
        {0, 6}
    };

    for (int lotto : lottos) {
        if(find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()) {
            base_result += 1;
        }
    }

    int max_rank = ranks[base_result + number_of_0];
    int min_rank = ranks[base_result];

    answer.push_back(max_rank);
    answer.push_back(min_rank);
    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({44, 1, 0, 0, 31, 25}, {31, 10, 45, 1, 6, 19}), vector<int>{3, 5});
    t.check(solution({0, 0, 0, 0, 0, 0}, {38, 19, 20, 40, 15, 25}), vector<int>{1, 6});
    t.check(solution({45, 4, 35, 20, 3, 9}, {20, 9, 3, 45, 4, 35}), vector<int>{1, 1});

    // 아래는 직접 추가한 경계 케이스
    t.check("하나도 안 맞고 0 도 없음", solution({1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}), vector<int>{6, 6});
    t.check("1개 맞고 0 없음 (1개도 6등)", solution({1, 2, 3, 4, 5, 6}, {1, 8, 9, 10, 11, 12}), vector<int>{6, 6});
    t.check("0 하나로 1개 -> 2개", solution({0, 2, 3, 4, 5, 6}, {2, 8, 9, 10, 11, 12}), vector<int>{5, 6});
    return t.report();
}
