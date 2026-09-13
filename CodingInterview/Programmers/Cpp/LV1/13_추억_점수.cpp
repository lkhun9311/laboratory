// https://school.programmers.co.kr/learn/courses/30/lessons/176963?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!13_추억_점수.py

// Number of times solving questions: 1
// 2026-09-13

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>    // 스켈레톤에 없으므로 직접 추가한다
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    // 규칙 1. name[i] 를 그리워하는 정도가 yearning[i] 다.
    // 규칙 2. 사진마다 찍힌 사람들의 점수 합을 구한다. name 에 없는 사람은 0점.

    vector<int> answer;

    // 이름 -> 점수 표. 사진마다 name 을 훑으면 O(사진수 x 인원 x name) 이 된다.
    unordered_map<string, int> score_table;
    int name_size = name.size();

    for (int idx = 0; idx < name_size; idx++) {
        score_table[name[idx]] = yearning[idx];
    }

    for (const vector<string>& persons : photo) {
        int score = 0;

        for (const string& person : persons) {
            // find 로 존재를 먼저 확인한다.
            // score_table[person] 을 바로 쓰면 없는 이름이 0 으로 "생겨버린다". (규칙 2)
            // count(person) 이나 C++20 의 contains(person) 도 같은 일을 한다.
            if (score_table.find(person) != score_table.end()) {
                score += score_table[person];
            }
        }

        answer.push_back(score);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({"may", "kein", "kain", "radi"}, {5, 10, 1, 3},
                     {{"may", "kein", "kain", "radi"},
                      {"may", "kein", "brin", "deny"},
                      {"kon", "kain", "may", "coni"}}),
            vector<int>{19, 15, 6});
    t.check(solution({"kali", "mari", "don"}, {11, 1, 55},
                     {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}}),
            vector<int>{67, 0, 55});
    t.check(solution({"may", "kein", "kain", "radi"}, {5, 10, 1, 3},
                     {{"may"}, {"kein", "deny", "may"}, {"kon", "coni"}}),
            vector<int>{5, 15, 0});

    // 아래는 직접 추가한 경계 케이스
    t.check("아무도 아는 사람이 없음", solution({"a"}, {7}, {{"x", "y"}}), vector<int>{0});
    t.check("한 명 한 장", solution({"a"}, {100}, {{"a"}}), vector<int>{100});
    return t.report();
}
