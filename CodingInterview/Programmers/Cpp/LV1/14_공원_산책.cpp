// https://school.programmers.co.kr/learn/courses/30/lessons/172928?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/14_공원_산책.py

// Number of times solving questions: 1
// 2026-09-14

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

// 규칙 1. 'S' 한 칸에서 출발해 routes 의 명령을 순서대로 수행한다.
// 규칙 2. 한 명령은 "E 2" 처럼 [방향 문자][공백][칸 수] 형태다.
// 규칙 3. 이동 도중 공원을 벗어나거나 'X' 를 만나면 그 명령을 통째로 무시한다.
//         → 도착지만 검사하면 틀린다. 지나는 칸을 전부 검사해야 한다.
// 규칙 4. 모든 명령을 마친 뒤의 위치를 {행, 열} 로 돌려준다.
//
// 규칙 3이 이 문제의 전부다. 예제 3이 정확히 그 함정을 찌른다.
//
//   O S O      시작 (0,1)
//   O O O      "S 3" → 도착지 (3,1) 은 'O' 라서 겉보기엔 갈 수 있다
//   O X O      ↓ 지나는 길 (2,1) 이 'X'
//   O O O      → 명령 전체 무시. 제자리
//
//   도착지만 검사  : (3,1)='O' → 이동한다   ✗ 오답
//   지나는 칸 검사 : (2,1)='X' → 무시한다   ✓ 정답
//
// 그래서 한 명령을 두 단계로 나눈다. 먼저 끝까지 걸어보며 확인만 하고,
// 무사히 끝났을 때에만 실제 좌표에 반영한다. 걸으면서 바로 반영하면
// 중간에 막혔을 때 되돌릴 방법이 없다.
vector<int> solution(vector<string> park, vector<string> routes) {
    int row_size = park.size();
    int col_size = park[0].size();  // 정사각형이 아니다. 세로·가로를 따로 잡는다

    unordered_map<string, pair<int, int>> direction = {
        {"N", {-1, 0}},
        {"S", { 1, 0}},
        {"W", { 0,-1}},
        {"E", { 0, 1}}
    };

    // 시작점 'S' 찾기. 공원에 단 하나뿐이다
    int row = 0;
    int col = 0;
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if ('S' == park[i][j]) {
                row = i;
                col = j;
                break;
            }
        }
    }

    for (const auto& route : routes) {
        // C++ 에는 split 이 없다. stringstream 의 >> 가 공백으로 끊어 준다
        string command;
        int number;
        stringstream ss(route);
        ss >> command >> number;

        auto [dr, dc] = direction[command];

        // nr, nc 는 "가정해 본 위치". 확인이 끝나기 전까지 row, col 은 건드리지 않는다
        int nr = row;
        int nc = col;
        bool valid = true;

        for (int i = 0; i < number; i++) {
            nr += dr;
            nc += dc;

            // 범위 검사를 격자 접근보다 먼저 해야 한다. 순서가 바뀌면 범위 밖을 읽는다
            if ((nr < 0 || nr >= row_size) || (nc < 0 || nc >= col_size)) {
                valid = false;
                break;
            }
            if (park[nr][nc] == 'X') {
                valid = false;
                break;
            }
        }

        // 한 칸도 막히지 않았을 때에만 확정한다
        if (valid) {
            row = nr;
            col = nc;
        }
    }

    return {row, col};
}

int main() {
    Tester t("solution");
    t.check(solution({"SOO", "OOO", "OOO"}, {"E 2", "S 2", "W 1"}), vector<int>{2, 1});
    t.check(solution({"SOO", "OXX", "OOO"}, {"E 2", "S 2", "W 1"}), vector<int>{0, 1});
    t.check(solution({"OSO", "OOO", "OXO", "OOO"}, {"E 2", "S 3", "W 1"}), vector<int>{0, 0});
    // 경계 ① 첫 명령부터 무시된다
    t.check(solution({"SOO", "OOO", "OOO"}, {"N 1", "E 1"}), vector<int>{0, 1});
    // 경계 ② 모든 명령이 무시되어 시작점 그대로
    t.check(solution({"OOO", "OSO", "OOO"}, {"N 2", "S 2", "W 2", "E 2"}), vector<int>{1, 1});
    // 경계 ③ 세로·가로가 다른 공원에서 벽에 딱 붙어 끝난다
    t.check(solution({"OOOOO", "OOOOS"}, {"S 1", "W 4"}), vector<int>{1, 0});
    return t.report();
}
