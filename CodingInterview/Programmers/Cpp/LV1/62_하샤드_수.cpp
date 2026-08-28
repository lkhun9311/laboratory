// https://school.programmers.co.kr/learn/courses/30/lessons/12947?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!62_하샤드_수.py

// Number of times solving questions: 1
// 2026-08-28

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

bool solution(int x) {
    // 규칙. 자릿수의 합으로 x가 나누어떨어지면 하샤드 수다.
    //      자릿수 합을 구하는 반복문은 값을 0까지 깎아야 끝나므로,
    //      나중에 나눌 원본 x는 건드리지 않고 복사본을 깎는다.
    int remaining = x;
    int digit_sum = 0;
    while (remaining > 0) {
        digit_sum += remaining%10;
        remaining /= 10;
    }

    return x % digit_sum == 0;
}

int main() {
    Tester t("solution");
    t.check(solution(10), true);
    t.check(solution(12), true);
    t.check(solution(11), false);
    t.check(solution(13), false);
    t.check("한 자리 (항상 참)", solution(7), true);
    t.check("최댓값 10000", solution(10000), true);
    t.check("네 자리 거짓", solution(9999), false);
    return t.report();
}
