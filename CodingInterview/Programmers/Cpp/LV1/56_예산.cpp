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

int solution(vector<int> d, int budget) {
    // 규칙. 신청 금액은 전액 지원하거나 아예 안 하거나 둘 중 하나다.
    //      "지원 부서 수"를 최대로 하는 게 목표이므로 싼 부서부터 채우는 것이 항상 최적이다.
    //      (어떤 답이 k개라면 그 k개를 가장 싼 k개로 바꿔도 총액이 늘지 않으므로)
    int answer = 0;
    int spent = 0;

    // C++ sort 는 제자리 정렬이고 값으로 받은 d 는 복사본이므로 그냥 정렬해도 된다.
    sort(d.begin(), d.end());

    for (int cost : d) {
        if (spent + cost > budget) {   // 예산과 같아지는 것은 허용, 넘으면 중단
            break;
        }
        spent += cost;
        answer += 1;
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1,3,2,5,4}, 9), 3);
    t.check(solution({2,2,3,3}, 10), 4);
    t.check("하나만, 딱 맞음", solution({1}, 1), 1);
    t.check("하나만, 모자람", solution({2}, 1), 0);
    t.check("예산과 정확히 같음", solution({1,2,3}, 6), 3);
    t.check("1 모자람", solution({1,2,3}, 5), 2);
    t.check("최대 크기 100개", solution(vector<int>(100, 100000), 9999999), 99);
    return t.report();
}
