// https://school.programmers.co.kr/learn/courses/30/lessons/12928?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!73_약수의_합.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(int n) {
    int answer = 0;

    int i = 1;
    while (i*i <= n) {
        if (n%i == 0) {
            answer += i;
            if (i != n/i) {
                answer += n/i;
            }
        }

        i += 1;
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(12), 28);
    t.check(solution(5), 6);
    t.check("n=1", solution(1), 1);
    t.check("n=0", solution(0), 0);
    t.check("최댓값 3000", solution(3000), 9360);
    t.check("제곱수 36", solution(36), 91);
    t.check("제곱수 49", solution(49), 57);
    return t.report();
}
