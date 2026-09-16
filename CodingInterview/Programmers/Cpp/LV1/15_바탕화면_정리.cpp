// https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!15_바탕화면_정리.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int rows = wallpaper.size();
    int cols = wallpaper[0].size();

    int minRow = rows;
    int minCol = cols;
    int maxRow = 0;
    int maxCol = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (wallpaper[row][col] != '#') {
                continue;
            }

            minRow = min(minRow, row);
            minCol = min(minCol, col);
            maxRow = max(maxRow, row);
            maxCol = max(maxCol, col);
        }
    }

    return {minRow, minCol, maxRow + 1, maxCol + 1};
}

int main() {
    Tester t("solution");
    t.check(solution({".#...", "..#..", "...#."}), vector<int>{0, 1, 3, 4});
    t.check(solution({"..........", ".....#....", "......##..", "...##.....", "....#....."}),
            vector<int>{1, 3, 5, 8});
    t.check(solution({".##...####", "#..#.#....", "#.#.#.#..#", "#..#.#....", ".##...####"}),
            vector<int>{0, 0, 5, 10});
    t.check(solution({"..", "#."}), vector<int>{1, 0, 2, 1});

    // 아래는 직접 추가한 경계 케이스
    t.check("1x1 에 파일 하나", solution({"#"}), vector<int>{0, 0, 1, 1});
    t.check("파일 하나, 오른쪽 아래 끝", solution({"...", "...", "..#"}), vector<int>{2, 2, 3, 3});
    t.check("한 행에 흩어져 있음", solution({"#.#", "...", "..."}), vector<int>{0, 0, 1, 3});
    t.check("한 열에 흩어져 있음", solution({"#..", "...", "#.."}), vector<int>{0, 0, 3, 1});
    return t.report();
}
