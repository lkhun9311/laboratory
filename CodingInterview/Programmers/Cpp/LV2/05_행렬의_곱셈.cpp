// https://school.programmers.co.kr/learn/courses/30/lessons/12949?language=cpp
// 출처: 구현
// 대응 Python 풀이: ../../Python/LV2/05_행렬의_곱셈.py

// Number of times solving questions: 1
// 2026-09-11

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // 규칙 1. 결과의 (i, j) 자리는 arr1 의 i번째 "행" 과 arr2 의 j번째 "열" 을
    //         앞에서부터 짝지어 곱한 뒤 전부 더한 값이다.
    // 규칙 2. 곱할 수 있는 형태만 주어진다 = arr1 의 열 수와 arr2 의 행 수가 같다.
    // 규칙 3. 행·열 최대 100, 원소 -10~20 → 합의 절댓값이 최대 20*20*100 = 40,000. int 로 충분하다.

    // 세 크기에 이름을 붙여 두는 것이 이 문제의 핵심이다.
    // 삼중 루프에서 i, j, k 가 어느 행렬의 무엇인지 헷갈리는 것이 유일한 난관이기 때문이다.
    int row = arr1.size();      // 결과의 행 수  = arr1 의 행 수
    int mid = arr2.size();      // 짝지어 곱하는 횟수 (arr1[0].size() 와 같다 — 규칙 2)
    int col = arr2[0].size();   // 결과의 열 수  = arr2 의 열 수

    // R행 C열을 0으로 채워 만든다. vector<int>(col, 0) 짜리를 row 개 만드는 형태다.
    // Python 의 [[0]*col for _ in range(row)] 에 대응한다.
    vector<vector<int>> answer(row, vector<int>(col, 0));

    // i: 결과의 행, j: 결과의 열, k: 짝짓기 위치.
    // k 가 arr1 에서는 "열", arr2 에서는 "행" 으로 쓰이는 것이 행렬 곱의 정의 그 자체다. (규칙 1)
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < mid; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({{1, 4}, {3, 2}, {4, 1}},
                     {{3, 3}, {3, 3}}),
            vector<vector<int>>{{15, 15}, {15, 15}, {15, 15}});
    t.check(solution({{2, 3, 2}, {4, 2, 4}, {3, 1, 4}},
                     {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}}),
            vector<vector<int>>{{22, 22, 11}, {36, 28, 18}, {29, 20, 14}});

    // 아래는 직접 추가한 경계 케이스
    // 정사각형이 아닌 경우 — row, mid, col 이 전부 다르다
    t.check("2x3 * 3x2", solution({{1, 2, 3}, {4, 5, 6}},
                                  {{7, 8}, {9, 10}, {11, 12}}),
            vector<vector<int>>{{58, 64}, {139, 154}});
    // 최소 크기 2x2
    t.check("2x2 최소", solution({{1, 0}, {0, 1}}, {{5, 6}, {7, 8}}),
            vector<vector<int>>{{5, 6}, {7, 8}});
    // 음수 원소
    t.check("음수 포함", solution({{-10, 2}, {3, -4}}, {{1, -2}, {-3, 4}}),
            vector<vector<int>>{{-16, 28}, {15, -22}});
    return t.report();
}
