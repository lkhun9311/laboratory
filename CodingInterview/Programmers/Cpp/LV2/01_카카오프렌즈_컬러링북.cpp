// https://school.programmers.co.kr/learn/courses/30/lessons/1829?language=cpp
// 출처: 구현
// 대응 Python 풀이: ../../Python/LV2/01_카카오프렌즈_컬러링북.py

// Number of times solving questions: 1
// 2026-09-15

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 규칙 1. 0 은 색칠되지 않은 칸이다. 영역이 아니다.
// 규칙 2. 상하좌우로 맞닿은 같은 색 칸끼리 한 영역이다. 대각선은 닿은 것이 아니다.
// 규칙 3. 영역의 개수와, 그중 가장 큰 영역의 칸 수를 {개수, 최대크기} 로 돌려준다.
//
// 지금까지의 격자 문제와 다른 점은 "얼마나 멀리 가는지 미리 모른다"는 것이다.
// 14번 공원 산책은 갈 칸 수가 명령에 적혀 있었다. 여기서는 번지는 곳까지 번진다.
// 그래서 "앞으로 가 볼 칸"을 큐에 쌓아 두고 빌 때까지 꺼낸다 — 이것이 BFS다.
//
//   1 1 1 0     (0,0) 에서 시작해 같은 색 1 로만 번진다
//   1 2 2 0
//   1 0 0 1     (0,0) → (0,1) (1,0) → (0,2) (2,0) → ...
//   0 0 0 1     ↓ 큐가 빌 때까지
//   0 0 0 3     → 5칸짜리 영역 하나 완성
//   0 0 0 3
//
// 핵심은 visited 를 "꺼낼 때"가 아니라 "넣을 때" 켜는 것이다.
// 꺼낼 때 켜면 같은 칸이 큐에 여러 번 들어가 개수가 부풀고 큐도 터진다.
//
// 바깥의 이중 루프는 "아직 안 가 본 색칠된 칸"을 찾는 역할만 한다.
// 거기서 bfs 를 한 번 부르면 그 영역 하나가 통째로 visited 처리된다.
// 따라서 bfs 를 부른 횟수 = 영역의 개수다.

// 방향 배열은 루프 밖에 한 번만 둔다. 안에서 만들면 칸마다 새로 할당된다
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = { 0, 0,-1, 1};

int bfs(int m, int n, int r, int c, const vector<vector<int>>& picture, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    int count = 0;
    int color = picture[r][c];  // 시작 칸의 색. 이 색으로만 번진다

    q.push({r, c});
    visited[r][c] = true;       // 넣을 때 켠다

    while (!q.empty()) {
        // 매개변수 r, c 를 가리지 않도록 이름을 나눈다.
        // 같은 이름을 쓰면 컴파일은 되지만 시작 좌표가 사라진다
        auto [cur_r, cur_c] = q.front();
        q.pop();
        count++;

        for (int i = 0; i < 4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];

            // 범위 검사가 격자 접근보다 먼저여야 한다
            if (0 <= nr && nr < m && 0 <= nc && nc < n
                && color == picture[nr][nc] && !visited[nr][nc]) {
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }

    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // 이 문제는 채점기가 solution 을 한 프로세스에서 여러 번 부른다.
    // 전역 변수를 쓰면 이전 호출의 값이 남아 틀린다. 전부 지역 변수로 둔다
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<int> area_arr;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            // 색칠돼 있고 아직 안 가 본 칸 = 새 영역의 시작점
            if (picture[r][c] != 0 && !visited[r][c]) {
                area_arr.push_back(bfs(m, n, r, c, picture, visited));
            }
        }
    }

    int number_of_area = area_arr.size();
    int max_size_of_one_area = 0;
    if (!area_arr.empty()) {
        max_size_of_one_area = *max_element(area_arr.begin(), area_arr.end());
    }

    return {number_of_area, max_size_of_one_area};
}

int main() {
    Tester t("solution");
    t.check(solution(6, 4, {{1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3}}), vector<int>{4, 5});
    // 경계 ① 전부 0 — 영역이 하나도 없다
    t.check(solution(2, 2, {{0,0},{0,0}}), vector<int>{0, 0});
    // 경계 ② 1x1 한 칸
    t.check(solution(1, 1, {{5}}), vector<int>{1, 1});
    // 경계 ③ 같은 색이지만 대각선으로만 닿음 — 별개 영역이다
    t.check(solution(2, 2, {{1,0},{0,1}}), vector<int>{2, 1});
    // 경계 ④ 전부 같은 색 한 덩어리
    t.check(solution(3, 3, {{7,7,7},{7,7,7},{7,7,7}}), vector<int>{1, 9});
    // 경계 ⑤ 다른 색이 맞닿아 있으면 나뉜다
    t.check(solution(1, 4, {{1,1,2,2}}), vector<int>{2, 2});
    return t.report();
}
