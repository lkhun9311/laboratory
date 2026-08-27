// https://school.programmers.co.kr/learn/courses/30/lessons/12932?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!70_자연수_뒤집어_배열로_만들기.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
    // 규칙. n의 각 자리 숫자를 뒤집은 순서로 담는다.
    //      n이 100억까지 가므로 int(21억)로는 부족해 long long을 받는다.

    // n % 10 이 마지막 자리, n /= 10 이 그 자리를 버린다.
    // 꺼내지는 순서가 곧 뒤집힌 순서라 담기만 하면 된다.
    vector<int> answer;

    while (n > 0) {
        answer.push_back(n%10);
        n /= 10;
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(12345), vector<int>{5,4,3,2,1});
    t.check("한 자리", solution(7), vector<int>{7});
    t.check("0으로 끝남", solution(10), vector<int>{0,1});
    t.check("0이 여럿", solution(1000), vector<int>{0,0,0,1});
    t.check("최댓값 100억", solution(10000000000LL), vector<int>{0,0,0,0,0,0,0,0,0,0,1});
    return t.report();
}
