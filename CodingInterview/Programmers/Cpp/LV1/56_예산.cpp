// https://school.programmers.co.kr/learn/courses/30/lessons/12982?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!56_예산.py

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

// 규칙. 신청 금액은 전액 지원하거나 아예 안 하거나 둘 중 하나다.
//      "지원 부서 수"를 최대로 하는 것이 목표이므로 싼 부서부터 채우는 것이 항상 최적이다.
// 참고. d 는 값으로 받은 복사본이라 정렬해도 호출한 쪽에는 영향이 없다 (파이썬과 다른 점).
int solution(vector<int> d, int budget) {
    int answer = 0;
    int cost = 0;
    sort(d.begin(), d.end());
    for (const int& c : d) {
        cost += c;
        if (cost <= budget) {
            answer += 1;
        } else {
            break;
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1,3,2,5,4}, 9), 3);
    t.check(solution({2,2,3,3}, 10), 4);
    t.check("정렬 필요", solution({5,1,1}, 2), 2);
    t.check("예산과 정확히 같음", solution({1,2,3}, 6), 3);
    t.check("하나도 못 삼", solution({2}, 1), 0);
    t.check("최대 크기 100개", solution(vector<int>(100, 100000), 9999999), 99);
    return t.report();
}
