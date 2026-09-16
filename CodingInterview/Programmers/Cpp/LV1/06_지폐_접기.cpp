// https://school.programmers.co.kr/learn/courses/30/lessons/340199?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!06_지폐_접기.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    sort(wallet.begin(), wallet.end());
    int w = wallet[0];
    int h = wallet[1];
    sort(bill.begin(), bill.end());

    while (bill[0]>w || bill[1]>h) {
        bill[1] /= 2;
        sort(bill.begin(), bill.end());
        answer++;
    }

    return answer;
}

int main() {
    Tester t("solution");

    // 아래 기대값은 문제의 접기 규칙(긴 변을 반으로, 소수점은 버림)을 손으로 따라가 계산했다
    t.check("돌리면 바로 들어간다", solution({10, 20}, {20, 10}), 0);
    t.check("같은 크기", solution({1, 1}, {1, 1}), 0);
    t.check("두 번 접는다", solution({5, 5}, {10, 10}), 2);
    t.check("한 번 접으면 들어간다", solution({30, 15}, {26, 17}), 1);
    t.check("버림이 필요하다 (7 -> 3)", solution({3, 3}, {7, 3}), 1);
    t.check("4 -> 2 -> 1", solution({1, 1}, {4, 1}), 2);
    return t.report();
}
