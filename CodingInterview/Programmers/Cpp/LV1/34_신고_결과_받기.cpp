// https://school.programmers.co.kr/learn/courses/30/lessons/92334?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/34_신고_결과_받기.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> reporters_by_suspect;

    for (const string& report_record : report) {
        stringstream ss(report_record);
        string reporter, suspect;
        ss >> reporter >> suspect;
        reporters_by_suspect[suspect].insert(reporter);
    }

    unordered_map<string, int> emails;
    for (const auto& [suspect, reporters] : reporters_by_suspect) {
        int reporters_size = reporters.size();
        if (reporters_size >= k) {
            for (const string& reporter : reporters) {
                emails[reporter] += 1;
            }
        }
    }

    for (const string& user : id_list) {
        answer.push_back(emails[user]);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({"muzi","frodo","apeach","neo"},
                     {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"}, 2),
            vector<int>{2,1,1,0});
    t.check(solution({"con","ryan"}, {"ryan con","ryan con","ryan con","ryan con"}, 3),
            vector<int>{0,0});
    return t.report();
}
