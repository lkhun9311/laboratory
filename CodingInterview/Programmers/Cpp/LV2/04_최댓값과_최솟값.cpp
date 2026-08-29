// https://school.programmers.co.kr/learn/courses/30/lessons/12939?language=cpp
// 출처: 구현
// 대응 Python 풀이: ../../Python/LV2/!04_최댓값과_최솟값.py

// Number of times solving questions: 1
// 2026-08-29

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    // 규칙. 공백으로 구분된 정수들 중 최솟값과 최댓값을 "최솟값 최댓값" 문자열로 돌려준다.

    // 1. 개수를 모르므로 더 읽을 수 없을 때까지 돈다.
    //    int로 받으므로 문자열->숫자 변환이 자동이고 음수 부호도 처리된다.
    stringstream ss(s);
    int number;
    vector<int> numbers;
    while (ss >> number) {
        numbers.push_back(number);
    }

    // 2. min_element/max_element 는 위치 표식을 주므로 *로 값을 꺼낸다.
    int min_number = *min_element(numbers.begin(), numbers.end());
    int max_number = *max_element(numbers.begin(), numbers.end());

    // 3. 숫자를 그대로 + 하면 포인터 산술이 되므로 반드시 to_string으로 감싼다.
    return to_string(min_number) + " " + to_string(max_number);
}

int main() {
    Tester t("solution");
    t.check(solution("1 2 3 4"), "1 4");
    t.check(solution("-1 -2 -3 -4"), "-4 -1");
    t.check("최소 개수 2개", solution("-1 -1"), "-1 -1");
    t.check("사전순 함정", solution("1 10 2"), "1 10");
    t.check("부호 섞임", solution("100 -100"), "-100 100");
    return t.report();
}
