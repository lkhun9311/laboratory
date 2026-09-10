// https://school.programmers.co.kr/learn/courses/30/lessons/87389?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/35_나머지가_1이_되는_수_찾기.py

// Number of times solving questions: 1
// 2026-09-10

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    // 규칙 1. n % x == 1 을 만족하는 가장 작은 자연수 x 를 반환한다.
    // 규칙 2. n 은 3 이상 1,000,000 이하.

    // 답이 될 수 없는 값으로 초기화한다. x 는 최소 2 이상이므로 0 이 남으면 명백한 이상이다.
    // (n-1 같은 "답이 될 수 있는 값"을 기본값으로 두면 버그가 조용히 숨는다)
    int answer = 0;

    // x = 1 은 후보가 아니다. 어떤 수든 1 로 나누면 나머지가 0 이므로 절대 1 이 될 수 없다.
    // 따라서 2 부터 찾는다.
    //
    // 최악 O(n) = 100만 번이라 제한 안에서 충분히 통과한다.
    // (수학적으로는 n-1 의 약수 중 최솟값이라 O(sqrt(n))도 가능하지만,
    //  이미 통과하는 것을 더 빠르게 만드는 데 시간을 쓰지 않는다)
    for (int i = 2; i < n; i++) {
        if (n % i == 1) {
            answer = i;
            break;      // 가장 "작은" 값이 답이므로 첫 번째를 찾는 즉시 멈춘다. (규칙 1)
        }               // break 를 빼면 마지막으로 만족한 값이 남아 n=10 이 3 대신 9 가 된다
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(10), 3);
    t.check(solution(12), 11);

    // 아래는 직접 추가한 경계 케이스
    t.check("최솟값 n=3", solution(3), 2);
    t.check("후보가 여럿(작은 것)", solution(100), 3);
    t.check("n-1 만 답인 경우", solution(4), 3);
    t.check("최대치 n=1000000", solution(1000000), 3);
    return t.report();
}
