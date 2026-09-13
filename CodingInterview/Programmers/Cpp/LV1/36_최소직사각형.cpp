// https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=cpp
// 출처: 완전탐색
// 대응 Python 풀이: ../../Python/LV1/36_최소직사각형.py

// Number of times solving questions: 1
// 2026-09-13

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>    // max
using namespace std;

int solution(vector<vector<int>> sizes) {
    // 규칙 1. 명함은 돌려서 넣어도 된다 → 각 명함을 "긴 변, 짧은 변"으로 정규화할 수 있다.
    // 규칙 2. 모든 명함이 들어가는 가장 작은 지갑의 넓이를 구한다.
    // 규칙 3. 명함 최대 10,000장, 변 최대 1,000 → O(n) 이면 충분하고 넓이 최대 100만이라 int 로 족하다.

    int max_long = 0;       // 긴 변들 중 최댓값 = 지갑의 가로
    int max_short = 0;      // 짧은 변들 중 최댓값 = 지갑의 세로

    // 돌릴 수 있으므로 모든 명함의 긴 변을 한쪽 방향으로 맞춰 놓고 생각하면 된다. (규칙 1)
    // 그러면 지갑은 "가장 긴 긴변 x 가장 긴 짧은변" 하나로 정해진다.
    for (const vector<int>& card : sizes) {
        int long_side = max(card[0], card[1]);
        int short_side = min(card[0], card[1]);

        max_long = max(max_long, long_side);
        max_short = max(max_short, short_side);
    }

    return max_long * max_short;    // (규칙 2)
}

int main() {
    Tester t("solution");
    t.check(solution({{60, 50}, {30, 70}, {60, 30}, {80, 40}}), 4000);
    t.check(solution({{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}}), 120);
    t.check(solution({{14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11}}), 133);

    // 아래는 직접 추가한 경계 케이스
    t.check("명함 1장", solution({{3, 7}}), 21);
    t.check("전부 정사각", solution({{5, 5}, {5, 5}, {5, 5}}), 25);
    t.check("최대 크기", solution({{1000, 1000}, {1, 1}}), 1000000);
    return t.report();
}
