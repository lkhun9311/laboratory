// https://school.programmers.co.kr/learn/courses/30/lessons/150370?language=cpp
// 출처: 2023 KAKAO BLIND RECRUITMENT
// 대응 Python 풀이: ../../Python/LV1/!20_개인정보_수집_유효기간.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int toDays(string date) {
    stringstream ss(date);
    string y, m, d;

    getline(ss, y, '.');
    getline(ss, m, '.');
    getline(ss, d, '.');

    return (stoi(y)*12 + stoi(m))*28 + stoi(d);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int days_of_today = toDays(today);

    unordered_map<string, int> terms_map;
    int terms_size = terms.size();
    for (int i=0; i<terms_size; i++) {
        string t;
        int t_m;
        stringstream ss(terms[i]);
        ss >> t >> t_m;
        terms_map[t] = t_m;
    }

    int privacy_size = privacies.size();
    for (int i=0; i<privacy_size; i++) {
        string privacy = privacies[i];
        string p_d;
        string p_t;
        stringstream ss_privacy(privacy);
        ss_privacy >> p_d >> p_t;
        int term_month = terms_map[p_t];

        int days_of_p = toDays(p_d) + term_month*28;

        if (days_of_today >= days_of_p) {
            answer.push_back(i+1);
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("2022.05.19", {"A 6", "B 12", "C 3"},
                     {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"}),
            vector<int>{1, 3});
    t.check(solution("2020.01.01", {"Z 3", "D 5"},
                     {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"}),
            vector<int>{1, 4, 5});

    // 아래는 직접 추가한 경계 케이스
    t.check("유효기간 마지막 날 — 아직 유효",
            solution("2022.01.28", {"A 1"}, {"2022.01.01 A"}), vector<int>{});
    t.check("하루 지나면 파기 (1월 1일 + 1달 = 1월 29일부터 만료)",
            solution("2022.01.29", {"A 1"}, {"2022.01.01 A"}), vector<int>{1});
    t.check("같은 날 수집, 기간 1달 — 유효",
            solution("2022.01.01", {"A 1"}, {"2022.01.01 A"}), vector<int>{});
    t.check("전부 파기", solution("2030.12.28", {"A 1", "B 1"}, {"2000.01.01 A", "2000.01.01 B"}),
            vector<int>{1, 2});
    // 이 문제에서 모든 달은 28일이므로 날짜는 1~28 만 존재한다 (31 일은 입력으로 올 수 없다)
    t.check("연도가 넘어간다", solution("2023.01.01", {"A 12"}, {"2021.12.28 A"}), vector<int>{1});
    return t.report();
}
