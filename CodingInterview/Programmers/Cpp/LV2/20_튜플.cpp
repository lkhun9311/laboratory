// https://school.programmers.co.kr/learn/courses/30/lessons/64065?language=cpp
// 출처: 2019 카카오 개발자 겨울 인턴십
// 대응 Python 풀이: ../../Python/LV2/!20_튜플.py

// Number of times solving questions: 1
// 2026-09-20
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> mapNumber;
    string tmp_s;

    for (const auto& ch: s) {
        if (isdigit(ch)) {
            tmp_s.push_back(ch);
        } else if (!tmp_s.empty()) {
            mapNumber[stoi(tmp_s)]++;
            tmp_s.clear();
        }
    }

    vector<pair<int, int>> mapNumberCount;
    for(const auto& [number, count] : mapNumber) {
        mapNumberCount.push_back({count, number});
    }

    sort(mapNumberCount.begin(), mapNumberCount.end(), greater<>());
    for (const auto& [count, number] : mapNumberCount) {
        answer.push_back(number);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"), vector<int>{2, 1, 3, 4});
    t.check(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"), vector<int>{2, 1, 3, 4});
    t.check(solution("{{20,111},{111}}"), vector<int>{111, 20});
    t.check(solution("{{123}}"), vector<int>{123});
    t.check(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"), vector<int>{3, 2, 4, 1});

    // 아래는 직접 추가한 경계 케이스 (s 길이 5~1,000,000, 숫자 1~100,000, 원소 1~500개)
    t.check("원소 하나짜리 튜플", solution("{{1}}"), vector<int>{1});
    t.check("가장 큰 숫자", solution("{{100000},{100000,1}}"), vector<int>{100000, 1});
    t.check("집합 순서가 뒤섞여 있다",
            solution("{{2,1,3,4},{2},{2,1,3},{2,1}}"), vector<int>{2, 1, 3, 4});
    return t.report();
}
