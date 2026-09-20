// https://school.programmers.co.kr/learn/courses/30/lessons/42888?language=cpp
// 출처: 2019 KAKAO BLIND RECRUITMENT
// 대응 Python 풀이: ../../Python/LV2/!14_오픈채팅방.py

// Number of times solving questions: 1
// 2026-09-20
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> user_id_map;
    vector<pair<string, string>> command_arr;
    string command;
    string user_id;
    string nickname;

    for (const auto& r : record) {
        stringstream ss(r);
        ss >> command >> user_id >> nickname;
        command_arr.push_back({command, user_id});

        if (command == "Enter" || command == "Change") {
            user_id_map[user_id] = nickname;
        }
    }

    for(const auto& c : command_arr) {
        command = c.first;
        user_id = c.second;
        nickname = user_id_map[user_id];
        if (command == "Enter") {
            answer.push_back(nickname+"님이 들어왔습니다.");
        }

        if (command == "Leave") {
            answer.push_back(nickname+"님이 나갔습니다.");
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234",
                      "Enter uid1234 Prodo", "Change uid4567 Ryan"}),
            vector<string>{"Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.",
                           "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."});

    // 아래는 직접 추가한 경계 케이스
    t.check("기록 하나", solution({"Enter uid1 Muzi"}), vector<string>{"Muzi님이 들어왔습니다."});
    t.check("Change 는 출력하지 않는다",
            solution({"Enter uid1 Muzi", "Change uid1 Prodo"}),
            vector<string>{"Prodo님이 들어왔습니다."});
    t.check("마지막 닉네임이 앞선 기록에도 적용된다",
            solution({"Enter uid1 A", "Leave uid1", "Enter uid1 B", "Change uid1 C"}),
            vector<string>{"C님이 들어왔습니다.", "C님이 나갔습니다.", "C님이 들어왔습니다."});
    t.check("여러 번 바꿔도 최종 닉네임만",
            solution({"Enter uid1 A", "Change uid1 B", "Change uid1 C", "Leave uid1"}),
            vector<string>{"C님이 들어왔습니다.", "C님이 나갔습니다."});
    t.check("두 사람이 번갈아",
            solution({"Enter uid1 A", "Enter uid2 B", "Leave uid2", "Leave uid1"}),
            vector<string>{"A님이 들어왔습니다.", "B님이 들어왔습니다.",
                           "B님이 나갔습니다.", "A님이 나갔습니다."});
    return t.report();
}
