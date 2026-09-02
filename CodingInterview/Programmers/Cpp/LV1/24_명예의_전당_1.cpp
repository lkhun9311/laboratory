// https://school.programmers.co.kr/learn/courses/30/lessons/138477?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!24_명예의_전당_1.py

// Number of times solving questions: 1
// 2026-09-02

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    // 규칙. 상위 k개만 명예의 전당에 남기고, 매일 그중 최하위를 기록한다.
    //      매일 하나만 추가되므로 넘치는 것도 항상 하나뿐 -> pop_back 한 번이면 된다.
    //      정렬 후 마지막이 곧 최하위이므로 "들어갔는지" 를 따로 판단할 필요가 없다.
    vector<int> answer;
    vector<int> arr_k;

    for (int s : score) {
        arr_k.push_back(s);
        sort(arr_k.begin(), arr_k.end(), greater<int>());

        // size() 는 부호 없는 타입이라 int k 와 비교하려면 캐스팅한다.
        if ((int) arr_k.size() > k) {
            arr_k.pop_back();
        }

        // C++ 에는 음수 인덱스가 없다. 마지막 원소는 back().
        answer.push_back(arr_k.back());
    }
    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(3, {10, 100, 20, 150, 1, 100, 200}), vector<int>{10, 10, 10, 20, 20, 100, 100});
    t.check(solution(4, {0, 300, 40, 300, 20, 70, 150, 50, 500, 1000}),
            vector<int>{0, 0, 0, 0, 20, 40, 70, 70, 150, 300});
    t.check("전부 같은 점수", solution(3, {5,5,5,5,5,5,5}), vector<int>{5,5,5,5,5,5,5});
    t.check("계속 내려감", solution(3, {100,90,80,70,60,50,40}), vector<int>{100,90,80,80,80,80,80});
    return t.report();
}
