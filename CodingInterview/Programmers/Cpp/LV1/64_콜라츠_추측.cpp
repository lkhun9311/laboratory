// https://school.programmers.co.kr/learn/courses/30/lessons/12943?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!64_콜라츠_추측.py

// Number of times solving questions: 1
// 2026-08-30

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

bool is_even(long long num) {
    return num%2 == 0;
}

int solution(int num) {
    // 규칙. 짝수면 2로 나누고 홀수면 3배+1. 1이 될 때까지의 횟수를 센다.
    //      500번 안에 1이 되지 않으면 -1.
    // 주의. 입력은 800만이지만 계산 도중 값이 60조까지 올라간다 (num=6631675 일 때).
    //      int(21억)로는 반드시 오버플로가 나므로 계산용 변수는 long long 이어야 한다.
    int answer = 0;
    long long n = num;

    while (n > 1) {
        if (answer>=500) {
            return -1;
        }

        if (is_even(n)) {
            n /= 2;
        } else {
            n = n*3 + 1;
        }

        answer += 1;
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(6), 8);
    t.check(solution(16), 4);
    t.check(solution(626331), -1);
    t.check("num=1 은 0번", solution(1), 0);
    t.check("최대 반복 597번", solution(7464846), -1);
    t.check("499번 (경계 바로 아래)", solution(1585403), 499);
    t.check("정확히 500번 (통과)", solution(3027113), 500);
    t.check("501번 (500 초과 -> -1)", solution(1056935), -1);
    t.check("도중 60조까지 오름 (576번이라 -1)", solution(6631675), -1);
    return t.report();
}
