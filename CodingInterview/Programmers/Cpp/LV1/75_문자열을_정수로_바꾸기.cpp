// https://school.programmers.co.kr/learn/courses/30/lessons/12925?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!75_문자열을_정수로_바꾸기.py

// Number of times solving questions: 1
// 2026-08-30

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    // 규칙. 부호가 붙을 수 있는 문자열을 정수로.
    //      stoi 가 +/- 부호를 알아서 처리하므로 직접 다룰 필요가 없다.
    //      C++에서 int(s) 는 "형변환"이라 문자열에는 쓸 수 없다. 파싱은 stoi.
    return stoi(s);
}

int main() {
    Tester t("solution");
    t.check(solution("1234"), 1234);
    t.check(solution("-1234"), -1234);
    t.check("+ 부호", solution("+1234"), 1234);
    t.check("한 자리", solution("1"), 1);
    t.check("한 자리 음수", solution("-9"), -9);
    t.check("최대 길이 5", solution("99999"), 99999);
    t.check("최소 음수", solution("-9999"), -9999);
    return t.report();
}
