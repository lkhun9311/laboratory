// https://school.programmers.co.kr/learn/courses/30/lessons/250125?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/10_이웃한_칸.py

// Number of times solving questions: 1
// 2026-09-13

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    // 규칙 1. board[h][w] 와 상하좌우로 맞닿은 칸 중 같은 색인 칸의 개수를 센다.
    // 규칙 2. 정사각 격자 3x3 ~ 100x100. 탐색은 없고 이웃 네 칸만 본다.

    int answer = 0;

    // 방향 배열. 격자 문제의 절반은 이 두 줄에서 시작한다.
    // 상(-1,0) 하(1,0) 좌(0,-1) 우(0,1) 순서로 맞춰 둔다.
    // 크기가 4로 고정이므로 vector 대신 일반 배열로 충분하다.
    int dh[4] = {-1, 1, 0, 0};
    int dw[4] = { 0, 0,-1, 1};

    string color = board[h][w];
    int n = board.size();

    for (int i = 0; i < 4; i++) {
        int new_h = h + dh[i];
        int new_w = w + dw[i];

        // 범위 검사를 board 접근보다 "먼저" 한다.
        // 순서를 바꾸면 격자 밖 메모리를 읽고, 에러 없이 이상한 값이 나온다.
        // 모서리 칸에서 바로 걸리는 자리다.
        if (new_h < 0 || new_h >= n || new_w < 0 || new_w >= n) {
            continue;
        }

        if (color == board[new_h][new_w]) {
            answer += 1;        // (규칙 1)
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({{"blue", "red", "orange", "red"},
                      {"red", "red", "blue", "orange"},
                      {"blue", "orange", "red", "red"},
                      {"orange", "orange", "red", "blue"}}, 1, 1), 2);
    t.check(solution({{"yellow", "green", "blue"},
                      {"blue", "green", "yellow"},
                      {"yellow", "blue", "blue"}}, 0, 1), 1);

    // 아래는 직접 추가한 경계 케이스 - 전부 같은 색 3x3 에서 위치별 이웃 수
    vector<vector<string>> same = {{"a", "a", "a"}, {"a", "a", "a"}, {"a", "a", "a"}};
    t.check("모서리 - 이웃 2칸", solution(same, 0, 0), 2);
    t.check("변 - 이웃 3칸", solution(same, 0, 1), 3);
    t.check("가운데 - 이웃 4칸", solution(same, 1, 1), 4);
    t.check("이웃에 같은 색 없음",
            solution({{"a", "b", "a"}, {"b", "c", "b"}, {"a", "b", "a"}}, 1, 1), 0);
    return t.report();
}
