// https://school.programmers.co.kr/learn/courses/30/lessons/12910?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!84_나누어_떨어지는_숫자_배열.py

// Number of times solving questions: 1
// 2026-08-29

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    // 규칙. divisor로 나누어떨어지는 값만 골라 오름차순으로 돌려준다.
    //      하나도 없으면 {-1}. 거른 뒤에 정렬해야 정렬 대상이 최소가 된다.
    vector<int> answer;

    for (const int& number : arr) {
        if (number%divisor == 0) {
            answer.push_back(number);
        }
    }

    if (answer.empty()) {
        return {-1};
    }

    // sort 는 제자리 정렬이고 아무것도 돌려주지 않는다. 정렬한 뒤 따로 반환한다.
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({5,9,7,10}, 5), vector<int>{5,10});
    t.check(solution({2,36,1,3}, 1), vector<int>{1,2,3,36});
    t.check(solution({3,2,6}, 10), vector<int>{-1});
    t.check("원소 하나", solution({7}, 7), vector<int>{7});
    t.check("역순 입력", solution({100,50,25}, 25), vector<int>{25,50,100});
    return t.report();
}
