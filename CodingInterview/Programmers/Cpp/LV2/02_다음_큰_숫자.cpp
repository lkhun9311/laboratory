// https://school.programmers.co.kr/learn/courses/30/lessons/12911?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV2/!02_다음_큰_숫자.py

// Number of times solving questions: 1
// 2026-09-17
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countOneInN(int n) {
    string binary = "";

    while (n > 0) {
        binary += n%2 + '0';
        n /= 2;

        reverse(binary.begin(), binary.end());
    }

    return count(binary.begin(), binary.end(), '1');
}

int solution(int n) {
    int countOne = countOneInN(n);
    int nextN = n+1;

    while (true) {
        int countOneOfNextN = countOneInN(nextN);
        if (countOne == countOneOfNextN) {
            break;
        }
        nextN++;
    }

    return nextN;
}

int main() {
    Tester t("solution");
    t.check(solution(78), 83);
    t.check(solution(15), 23);

    // 아래는 직접 추가한 경계 케이스 (2진수로 손으로 확인했다)
    t.check("최소 입력 1 (1 -> 10)", solution(1), 2);
    t.check("2 = 10 -> 100", solution(2), 4);
    t.check("3 = 11 -> 101", solution(3), 5);
    t.check("7 = 111 -> 1011", solution(7), 11);
    t.check("1 이 연속으로 몰린 경우 (12 = 1100 -> 10001)", solution(12), 17);
    return t.report();
}
