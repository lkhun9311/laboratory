// https://school.programmers.co.kr/learn/courses/30/lessons/132267?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!30_콜라_문제.py

// Number of times solving questions: 1
// 2026-09-02

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

int solution(int a, int b, int n) {
    // 규칙. 빈 병 a개를 주면 콜라 b병을 받는다. 마신 콜라도 빈 병이 되어 다시 교환에 쓰인다.
    //      보유 빈 병이 a개 미만이면 더 교환할 수 없다.
    //      n <= 1,000,000 이고 정답이 int 범위를 넘지 않는다고 명시돼 있어 오버플로 걱정은 없다.
    int answer = 0;

    while (n >= a) {
        int trade_count = n/a;                 // 이번에 몇 번 교환할 수 있나
        int received_bottle = trade_count*b;   // 받은 콜라
        int remain_bottle = n%a;               // 교환에 못 쓰고 남은 빈 병

        answer += received_bottle;
        n = remain_bottle + received_bottle;   // 남은 것 + 마시고 생긴 빈 병
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(2, 1, 20), 19);
    t.check(solution(3, 1, 20), 9);
    t.check("나머지가 2 이상", solution(4, 1, 10), 3);
    t.check("b가 1보다 큼", solution(5, 2, 100), 64);
    t.check("a-b가 1", solution(3, 2, 10), 16);
    t.check("최소 입력", solution(2, 1, 2), 1);
    return t.report();
}
