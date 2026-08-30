// https://school.programmers.co.kr/learn/courses/30/lessons/68935?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!45_3진법_뒤집기.py

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

int solution(int n) {
    // 규칙. n을 3진법으로 바꿔 앞뒤로 뒤집은 뒤 다시 10진법으로.
    //      3진법 문자열을 만드는 내장 함수는 없으므로 % 3 과 / 3 으로 직접 만든다.
    //      읽는 쪽은 stoi(s, nullptr, 3) 이 해준다 (진법은 세 번째 인자).
    //      결과 최댓값은 129140161 (n=86093441) 이라 int 로 충분하다.
    string digits = "";
    while (n > 0) {
        digits = to_string(n%3) + digits;   // 앞에 붙여야 정상 순서의 3진법 표기
        n /= 3;
    }

    // reverse 는 제자리에서 뒤집고 아무것도 반환하지 않으므로 줄을 나눈다.
    reverse(digits.begin(), digits.end());

    return stoi(digits, nullptr, 3);
}

int main() {
    Tester t("solution");
    t.check(solution(45), 7);
    t.check(solution(125), 229);
    t.check("n=1", solution(1), 1);
    t.check("n=3 (3진법 10 -> 01)", solution(3), 1);
    t.check("최댓값 1억", solution(100000000), 56480240);
    t.check("결과 최댓값", solution(86093441), 129140161);
    return t.report();
}
