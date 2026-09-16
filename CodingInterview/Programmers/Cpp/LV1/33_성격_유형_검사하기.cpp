// https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp
// 출처: 연습문제 (2022 KAKAO TECH INTERNSHIP)
// 대응 Python 풀이: ../../Python/LV1/!33_성격_유형_검사하기.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> type;

    int choiceSize = choices.size();

    for (int i=0; i<choiceSize; i++) {
        int tmp_score = choices[i];
        int score = abs(tmp_score - 4);

        if (tmp_score > 4) {
            type[survey[i][1]] += score;
        } else {
            type[survey[i][0]] += score;
        }
    }

    vector<string> types = {"RT", "CF", "JM", "AN"};

    for (const string& t : types) {
        char type_0 = t[0];
        char type_1 = t[1];
        if (type[type_0] < type[type_1]) {
            answer += type_1;
        } else {
            answer += type_0;
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({"AN", "CF", "MJ", "RT", "NA"}, {5, 3, 2, 7, 5}), string("TCMA"));
    t.check(solution({"TR", "RT", "TR"}, {7, 1, 3}), string("RCJA"));

    // 아래는 직접 추가한 경계 케이스
    t.check("모두 '모름'(4) — 전부 동점이라 앞 글자", solution({"AN", "CF", "MJ", "RT"}, {4, 4, 4, 4}),
            string("RCJA"));
    t.check("질문 하나", solution({"NA"}, {7}), string("RCJA"));
    t.check("뒤 글자만 이긴다", solution({"RT", "CF", "JM", "AN"}, {7, 7, 7, 7}), string("TFMN"));
    t.check("앞 글자만 이긴다", solution({"RT", "CF", "JM", "AN"}, {1, 1, 1, 1}), string("RCJA"));
    t.check("같은 지표가 서로 상쇄돼 동점", solution({"RT", "TR"}, {1, 1}), string("RCJA"));
    return t.report();
}
