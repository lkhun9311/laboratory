// https://school.programmers.co.kr/learn/courses/30/lessons/160585?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV2/!77_혼자서_하는_틱택토.py

// Number of times solving questions: 1
// 2026-09-21
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_win(char ch, const vector<string>& board) {
    for (int i=0; i<3; i++) {
        int ch_row_count = count(board[i].begin(), board[i].end(), ch);
        if (ch_row_count == 3) {
            return true;
        }

        if (
            board[0][i] == ch &&
            board[1][i] == ch &&
            board[2][i] == ch
        ) {
            return true;
        }
    }

    if (
        board[0][0] == ch &&
        board[1][1] == ch &&
        board[2][2] == ch
    ) {
        return true;
    }

    if (
        board[0][2] == ch &&
        board[1][1] == ch &&
        board[2][0] == ch
    ) {
        return true;
    }

    return false;
}

int solution(vector<string> board) {
    int o_count = 0;
    int x_count = 0;

    for (int r=0; r<3; r++) {
        o_count += count(board[r].begin(), board[r].end(), 'O');
        x_count += count(board[r].begin(), board[r].end(), 'X');
    }

    bool o_wins = is_win('O', board);
    bool x_wins = is_win('X', board);

    if (o_count<x_count || o_count > x_count+1) {
        return 0;
    }

    if (o_wins && x_wins) {
        return 0;
    }

    if (o_wins && o_count != x_count+1) {
        return 0;
    }

    if (x_wins && o_count != x_count) {
        return 0;
    }

    return 1;
}

int main() {
    Tester t("solution");
    t.check(solution({"O.X", ".O.", "..X"}), 1);
    t.check(solution({"OOO", "...", "XXX"}), 0);
    t.check(solution({"...", "...", "..."}), 1);

    // 아래는 직접 추가한 경계 케이스
    t.check("O 만 하나", solution({"O..", "...", "..."}), 1);
    t.check("X 만 하나 — O 가 먼저여야 한다", solution({"X..", "...", "..."}), 0);
    t.check("O 가 두 개 더 많다", solution({"OO.", "...", "..."}), 0);
    // O 3 : X 2 로 O 가 하나 많고 O 가 이겼으므로 가능한 판이다
    t.check("O 가 이기고 개수도 맞다", solution({"OOO", "XX.", "..."}), 1);
    // O 3 : X 3 인데 O 가 이겼다 -> O 가 이기고도 한 수 더 둔 셈이라 불가능
    t.check("O 가 이겼는데 개수가 같다", solution({"OOO", "XX.", "X.."}), 0);
    t.check("X 가 이기고 개수도 맞다", solution({"XXX", "OO.", "O.."}), 1);
    // O 5 : X 4, 승리 줄 없음 -> 무승부로 가득 찬 판
    t.check("가득 찬 판, 아무도 못 이김", solution({"OXO", "XXO", "OOX"}), 1);
    return t.report();
}
