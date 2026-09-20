// https://school.programmers.co.kr/learn/courses/30/lessons/77485?language=cpp
// 출처: 2021 Dev-Matching: 웹 백엔드 개발자(상반기)
// 대응 Python 풀이: ../../Python/LV2/!105_행렬_테두리_회전하기.py

// Number of times solving questions: 1
// 2026-09-20
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int value = 1;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (int row=0; row<rows; row++) {
        for (int column=0; column<columns; column++) {
            matrix[row][column] = value++;
        }
    }

    deque<int> dq;
    for (const auto& query : queries) {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        for (int i=y1; i<y2; i++) {
            dq.push_back(matrix[x1][i]);
        }

        for (int i=x1; i<x2; i++) {
            dq.push_back(matrix[i][y2]);
        }

        for (int i=y2; i>y1; i--) {
            dq.push_back(matrix[x2][i]);
        }

        for (int i=x2; i>x1; i--) {
            dq.push_back(matrix[i][y1]);
        }

        answer.push_back(*min_element(dq.begin(), dq.end()));
        int dq_b = dq.back();
        dq.pop_back();
        dq.push_front(dq_b);
        int j = 0;

        for (int i=y1; i<y2; i++) {
            matrix[x1][i] = dq[j];
            j++;
        }

        for (int i=x1; i<x2; i++) {
            matrix[i][y2] = dq[j];
            j++;
        }

        for (int i=y2; i>y1; i--) {
            matrix[x2][i] = dq[j];
            j++;
        }

        for (int i=x2; i>x1; i--) {
            matrix[i][y1] = dq[j];
            j++;
        }

        dq.clear();
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(6, 6, {{2, 2, 5, 4}, {3, 3, 6, 6}, {5, 1, 6, 3}}), vector<int>{8, 10, 25});
    t.check(solution(3, 3, {{1, 1, 2, 2}, {1, 2, 2, 3}, {2, 1, 3, 2}, {2, 2, 3, 3}}),
            vector<int>{1, 1, 5, 3});
    t.check(solution(100, 97, {{1, 1, 100, 97}}), vector<int>{1});

    // 아래는 직접 추가한 경계 케이스 (rows/columns 3~100, 질의 1~10,000)
    t.check("가장 작은 테두리 2x2", solution(3, 3, {{1, 1, 2, 2}}), vector<int>{1});
    t.check("같은 자리를 네 번 돌리면 제자리",
            solution(3, 3, {{1, 1, 2, 2}, {1, 1, 2, 2}, {1, 1, 2, 2}, {1, 1, 2, 2}}),
            vector<int>{1, 1, 1, 1});
    t.check("한 줄짜리 가로 테두리", solution(3, 4, {{1, 1, 1, 4}}), vector<int>{1});
    t.check("한 줄짜리 세로 테두리", solution(4, 3, {{1, 1, 4, 1}}), vector<int>{1});
    return t.report();
}
