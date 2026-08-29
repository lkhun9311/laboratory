// https://school.programmers.co.kr/learn/courses/30/lessons/12901?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!87_2016년.py

// Number of times solving questions: 1
// 2026-08-29

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

string solution(int a, int b) {
    // 규칙 1. 2016년 1월 1일은 금요일이고, 2016년은 윤년이라 2월이 29일이다.
    // 규칙 2. "1월 1일부터 며칠 지났는가"를 7로 나눈 나머지로 요일을 정한다.
    //        1월 1일 자신은 0일 지난 날이므로 b가 아니라 b - 1 이다.
    //        (파이썬과 달리 음수 인덱스가 없으므로 이 방식이 유일하게 안전하다)
    vector<int> DAYS_IN_MONTH = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> WEEKDAYS = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

    int elapsed_days = b-1;
    int elapsed_months = a-1;

    for (int month = 0; month < elapsed_months; month++) {
        elapsed_days += DAYS_IN_MONTH[month];
    }

    return WEEKDAYS[elapsed_days%7];
}

int main() {
    Tester t("solution");
    t.check(solution(5, 24), "TUE");
    t.check("1월 1일", solution(1, 1), "FRI");
    t.check("1월 2일", solution(1, 2), "SAT");
    t.check("윤일 2월 29일", solution(2, 29), "MON");
    t.check("12월 31일", solution(12, 31), "SAT");
    return t.report();
}
