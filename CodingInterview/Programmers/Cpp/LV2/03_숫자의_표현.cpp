// https://school.programmers.co.kr/learn/courses/30/lessons/12924?language=cpp
// 출처: 구현
// 대응 Python 풀이: ../../Python/LV2/!03_숫자의_표현.py

// Number of times solving questions: 1
// 2026-08-29

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    // 규칙. n을 연속한 자연수들의 합으로 쓰는 방법의 수.
    //      시작 숫자를 1부터 n/2까지 바꿔가며 전부 시도한다. (완전탐색)
    //      n 자기 자신(항이 하나뿐인 경우)은 미리 1로 세어둔다.
    int count = 1;

    for (int start = 1; start <= n/2; start++) {
        int total = start;
        int number = start;

        while (total < n) {
            number += 1;
            total += number;
        }

        if (total == n) {
            count += 1;
        }
    }

    return count;
}

int main() {
    Tester t("solution");
    t.check(solution(15), 4);
    t.check("n=1", solution(1), 1);
    t.check("n=2", solution(2), 1);
    t.check("n=3", solution(3), 2);
    t.check("n=10", solution(10), 2);
    t.check("최댓값 10000", solution(10000), 5);   // 10000 = 2^4 x 5^4, 홀수 약수 1/5/25/125/625
    t.check("2의 거듭제곱은 항상 1", solution(1024), 1);
    return t.report();
}
