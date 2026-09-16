// https://school.programmers.co.kr/learn/courses/30/lessons/389478?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!03_택배_상자_꺼내기.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 1;
    int rows = (n + (w-1)) / w;
    vector<vector<int>> box_maps(rows, vector<int>(w, 0));
    int box_num = 1;
    int target_row = -1;
    int target_col = -1;

    for (int row=0; row<rows; row++) {
        if (row%2 == 0) {
            for (int col=0; col<w; col++) {
                if (box_num>n) break;

                box_maps[row][col] = box_num;

                if (box_num == num) {
                    target_row = row;
                    target_col = col;
                }
                box_num++;
            }
        } else {
            for (int col=w-1; col>=0; col--) {
                if (box_num>n) break;

                box_maps[row][col] = box_num;
                if (box_num == num) {
                    target_row = row;
                    target_col = col;
                }

                box_num++;
            }
        }
    }

    for (int row=target_row+1; row<rows; row++) {
        if (box_maps[row][target_col] != 0) {
            answer++;
        }
    }


    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(22, 6, 8), 3);
    t.check(solution(13, 3, 6), 4);

    // 아래는 직접 추가한 경계 케이스
    t.check("상자 하나", solution(1, 1, 1), 1);
    t.check("한 줄만 있다 (위에 아무것도 없음)", solution(5, 5, 3), 1);
    t.check("한 칸씩 쌓인 탑의 맨 아래", solution(10, 1, 1), 10);
    t.check("한 칸씩 쌓인 탑의 맨 위", solution(10, 1, 10), 1);
    t.check("마지막 줄이 덜 찼다 — 그 열은 비어 있음", solution(7, 3, 1), 3);
    return t.report();
}
