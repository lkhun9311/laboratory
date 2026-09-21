// https://school.programmers.co.kr/learn/courses/30/lessons/92341?language=cpp
// 출처: 2022 KAKAO BLIND RECRUITMENT
// 대응 Python 풀이: ../../Python/LV2/!26_주차_요금_계산.py

// Number of times solving questions: 1
// 2026-09-21
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int base_time = fees[0];
    int base_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    map<string, vector<pair<string, int>>> carMaps;

    for (const auto& record : records) {
        string time_s, car_no, command;
        stringstream ss1(record);
        ss1 >> time_s >> car_no >> command;

        string hour, min;
        stringstream ss2(time_s);
        getline(ss2, hour, ':');
        getline(ss2, min);
        int mins = stoi(hour)*60 + stoi(min);
        carMaps[car_no].push_back({command, mins});
    }

    for (const auto& carMap : carMaps) {
        string car_no = carMap.first;
        const vector<pair<string, int>>& car_records = carMap.second;
        int total_mins = 0;
        string command;
        int record_mins = 0;
        int mins = 0;

        for (const auto& record : car_records) {
            command = record.first;
            mins = record.second;

            if (command == "IN") {
                record_mins = mins;
            }

            if (command == "OUT") {
                total_mins += mins - record_mins;
            }
        }

        if (command == "IN") {
            total_mins += (24*60-1) - mins;
        }

        if (total_mins <= base_time) {
            answer.push_back(base_fee);
        } else {
            int result_fee = base_fee + (((total_mins-base_time) + unit_time - 1)/unit_time) * unit_fee;
            answer.push_back(result_fee);
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({180, 5000, 10, 600},
                     {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT",
                      "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN",
                      "23:00 5961 OUT"}),
            vector<int>{14600, 34400, 5000});
    t.check(solution({120, 0, 60, 591},
                     {"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT",
                      "23:58 3961 IN"}),
            vector<int>{0, 591});
    // 00:00 입차 후 안 나감 -> 23:59 출차로 계산해 1439분. 461 + (1439-1)*10 = 14841
    t.check(solution({1, 461, 1, 10}, {"00:00 1234 IN"}), vector<int>{14841});

    // 아래는 직접 추가한 경계 케이스
    t.check("기본 시간 이하 — 기본 요금만",
            solution({100, 1000, 10, 100}, {"10:00 0001 IN", "11:00 0001 OUT"}),
            vector<int>{1000});
    t.check("기본 시간 정확히 채움",
            solution({60, 1000, 10, 100}, {"10:00 0001 IN", "11:00 0001 OUT"}),
            vector<int>{1000});
    t.check("1분 초과 — 단위 시간 하나로 올림",
            solution({60, 1000, 10, 100}, {"10:00 0001 IN", "11:01 0001 OUT"}),
            vector<int>{1100});
    t.check("같은 차가 여러 번 출입",
            solution({60, 1000, 10, 100},
                     {"10:00 0001 IN", "10:30 0001 OUT", "11:00 0001 IN", "11:30 0001 OUT"}),
            vector<int>{1000});
    // 두 차량 모두 780분 주차 -> 1000 + ((780-60)/10)*100 = 8200. 출력 순서가 0001, 9999 여야 한다
    t.check("차량번호 오름차순으로 나온다",
            solution({60, 1000, 10, 100},
                     {"10:00 9999 IN", "10:10 0001 IN", "23:00 9999 OUT", "23:10 0001 OUT"}),
            vector<int>{8200, 8200});
    return t.report();
}
