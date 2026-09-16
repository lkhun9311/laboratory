// https://school.programmers.co.kr/learn/courses/30/lessons/161989?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!16_덧칠하기.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int result = 0;
    vector<bool> painted(n, true);
    for (int i : section) {
        painted[i-1] = false;
    }

    for (int i : section) {
        if (!painted[i-1]) {
            int start = i-1;
            int end = min(start+m, n);
            for (int j=start; j<end; j++) {
                painted[j] = true;
            }

            result++;
        }
    }

    return result;
}

int main() {
    Tester t("solution");
    t.check(solution(8, 4, {2, 3, 6}), 2);
    t.check(solution(5, 4, {1, 3}), 1);
    t.check(solution(4, 1, {1, 2, 3, 4}), 4);

    // 아래는 직접 추가한 경계 케이스
    t.check("최소 입력 n=1", solution(1, 1, {1}), 1);
    t.check("롤러가 벽 전체를 덮는다", solution(5, 5, {1, 2, 3, 4, 5}), 1);
    t.check("롤러가 벽 끝을 넘어간다", solution(5, 4, {4, 5}), 1);
    t.check("칠할 곳이 떨어져 있다", solution(10, 2, {1, 5, 9}), 3);
    return t.report();
}
