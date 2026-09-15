// https://school.programmers.co.kr/learn/courses/30/lessons/12921?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!77_소수_찾기.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<bool> prime(n+1, true);
    prime[0] = false;
    prime[1] = false;

    for (int i=2; i*i<=n; i++) {
        if (prime[i]) {
            for (int j=i*i; j<=n; j+=i) {
                prime[j] = false;
            }
        }
    }

    answer = count(prime.begin(), prime.end(), true);
    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(10), 4);
    t.check(solution(5), 3);

    // 아래는 직접 추가한 경계 케이스
    t.check("최소 입력 n=2", solution(2), 1);
    t.check("n=4 (완전제곱수, 2*2 가 지워져야 한다)", solution(4), 2);
    t.check("n=25 (5*5 가 지워져야 한다)", solution(25), 9);
    t.check("최대 입력 n=1,000,000", solution(1000000), 78498);
    return t.report();
}
