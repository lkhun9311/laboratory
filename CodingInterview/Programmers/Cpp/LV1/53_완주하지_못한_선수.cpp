// https://school.programmers.co.kr/learn/courses/30/lessons/42576?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/53_완주하지_못한_선수.py

// Number of times solving questions: 1
// 2026-08-22

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> count_by_player;
    for (const string& player : participant) {
        count_by_player[player] += 1;
    }

    for (const string& player : completion) {
        count_by_player[player] -= 1;
    }

    for (const auto& [player, count] : count_by_player) {
        if (count != 0) {
            return player;
        }
    }

    throw runtime_error("정답이 없습니다. 입력이 제약을 위반했습니다.");
}

int main() {
    Tester t("solution");
    t.check(solution({"leo","kiki","eden"}, {"eden","kiki"}), "leo");
    t.check(solution({"marina","josipa","nikola","vinko","filipa"},
                     {"josipa","filipa","marina","nikola"}), "vinko");
    t.check(solution({"mislav","stanko","mislav","ana"}, {"stanko","ana","mislav"}), "mislav");
    t.check("참가자 1명", solution({"solo"}, {}), "solo");
    t.check("전원 동명이인", solution(vector<string>(5, "a"), vector<string>(4, "a")), "a");
    return t.report();
}
