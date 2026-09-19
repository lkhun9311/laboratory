// https://school.programmers.co.kr/learn/courses/30/lessons/92335?language=cpp
// 출처: 2022 KAKAO BLIND RECRUITMENT
// 대응 Python 풀이: ../../Python/LV2/!101_k진수에서_소수_개수_구하기.py

// Number of times solving questions: 1
// 2026-09-19
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long number) {
    if (number < 2) {
        return false;
    }

    for (long long i=2; i*i<=number; i++) {
        if (number%i == 0) {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string binary = "";

    while (n > 0) {
        binary.push_back(n%k + '0');
        n /= k;
    }
    reverse(binary.begin(), binary.end());
    binary.push_back('0');

    string token;
    for (const auto& b : binary) {
        if (b == '0') {
            if (!token.empty() && isPrime(stoll(token))) {
                answer++;
            }
            token.clear();
        } else {
            token.push_back(b);
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(437674, 3), 3);
    t.check(solution(110011, 10), 2);

    // 아래는 직접 추가한 경계 케이스
    t.check("n=1 — 1 은 소수가 아니다", solution(1, 10), 0);
    t.check("n=2 — 한 자리 소수", solution(2, 10), 1);
    t.check("3을 3진수로 = 10 -> 조각은 1 뿐", solution(3, 3), 0);
    t.check("맨 뒤 조각도 센다", solution(211, 10), 1);
    t.check("0 으로 끊긴 조각이 여러 개", solution(1010, 10), 0);
    // 1,000,000 을 3진수로 쓰면 1212210202001 -> 조각은 121221 · 2 · 2 · 1
    // (121221 은 자릿수 합이 9 라 3의 배수) 이므로 소수는 2 개다
    t.check("최대 입력 n=1,000,000 (k=3)", solution(1000000, 3), 2);
    return t.report();
}
