// https://school.programmers.co.kr/learn/courses/30/lessons/77884?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!40_약수의_개수와_덧셈.py

// Number of times solving questions: 1
// 2026-08-30

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

// C++ 은 쓰기 전에 정의돼 있어야 하므로 solution 위에 둔다.
int count_divisors(int number) {
    int count = 0;
    for (int divisor = 1 ; divisor <= number; divisor++) {
        if (number%divisor == 0) {
            count += 1;
        }
    }
    return count;
}

// 규칙. 약수 개수가 짝수면 그 수를 더하고 홀수면 뺀다.
//      더하고 빼는 대상은 "약수의 개수"가 아니라 "그 수 자체"다.
//      (약수 개수가 홀수인 수는 완전제곱수뿐 — 약수는 짝을 이루는데
//       완전제곱수만 sqrt 가 자기 자신과 짝이 되어 하나로 세지기 때문)
int solution(int left, int right) {
    int answer = 0;

    for (int number = left; number <= right; number++) {
        int count = count_divisors(number);
        if (count%2 == 0) {
            answer += number;
        } else {
            answer -= number;
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(13, 17), 43);
    t.check(solution(24, 27), 52);
    t.check("left=right=1", solution(1, 1), -1);
    t.check("1~10", solution(1, 10), 27);
    t.check("최대 범위 1~1000", solution(1, 1000), 479668);
    t.check("한 점 1000", solution(1000, 1000), 1000);
    t.check("999~1000", solution(999, 1000), 1999);
    return t.report();
}
