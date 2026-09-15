// https://school.programmers.co.kr/learn/courses/30/lessons/1844?language=cpp
// 출처: 깊이/너비 우선 탐색(DFS/BFS)
// 대응 Python 풀이: ../../Python/LV2/41_게임_맵_최단거리.py

// Number of times solving questions: 1
// 2026-09-15

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// 규칙 1. 1 은 통로, 0 은 벽. 상하좌우로만 움직인다.
// 규칙 2. (0,0) 에서 (n-1, m-1) 까지 지나는 칸 수의 최솟값을 돌려준다. 양 끝 칸도 센다.
// 규칙 3. 갈 수 없으면 -1.
//
// 01번 컬러링북과 코드 뼈대는 같다. 바뀌는 것은 두 가지뿐이다.
//   - 세는 것이 "칸 수"가 아니라 "그 칸까지의 거리"라서 큐에 거리를 함께 싣는다
//   - 끝까지 번질 필요가 없다. 도착점을 꺼내는 순간 끝이다
//
// 왜 처음 도달했을 때 멈춰도 되는가 — BFS 는 큐에서 꺼내는 순서가 거리 순이기 때문이다.
//
//   거리 1 칸들 전부  →  거리 2 칸들 전부  →  거리 3 칸들 전부  →  ...
//   ↓
//   도착점이 거리 7 에서 처음 꺼내졌다면,
//   거리 6 이하인 칸은 이미 전부 꺼내 봤고 그중에 도착점이 없었다는 뜻이다.
//   → 7 보다 짧은 경로는 존재하지 않는다. 더 볼 필요가 없다.
//
// DFS 로는 이 논리가 성립하지 않는다. DFS 가 처음 닿은 경로는 그저 "먼저 찾은" 경로라서
// 끝까지 다 뒤진 뒤 최솟값을 골라야 한다. 최단거리에 BFS 를 쓰는 이유가 이것이다.
//
// 큐가 비었는데 도착점을 못 만났다면 길이 끊긴 것이므로 -1.

// 방향 배열은 루프 밖에 한 번만 둔다
const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = { 0, 0,-1, 1};

int bfs(int n, int m, const vector<vector<int>>& maps, vector<vector<bool>>& visited) {
    // {행, 열, 그 칸까지의 거리}. 시작 칸도 세므로 1 부터 출발한다
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    visited[0][0] = true;  // 넣을 때 켠다

    while (!q.empty()) {
        // distance 는 std::distance 와 겹치는 이름이라 쓰지 않는다
        auto [cur_r, cur_c, dist] = q.front();
        q.pop();

        if (cur_r == n - 1 && cur_c == m - 1) {
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int nr = cur_r + dr[i];
            int nc = cur_c + dc[i];

            if (0 <= nr && nr < n && 0 <= nc && nc < m
                && maps[nr][nc] != 0 && !visited[nr][nc]) {
                q.push({nr, nc, dist + 1});
                visited[nr][nc] = true;
            }
        }
    }

    return -1;  // 큐가 비었는데 도착점을 못 만났다 = 길이 없다
}

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();  // 정사각형이 아니다. n, m 을 따로 잡는다

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    return bfs(n, m, maps, visited);
}

int main() {
    Tester t("solution");
    t.check(solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}}), 11);
    t.check(solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}}), -1);
    // 경계 ① 1x1 — 출발이 곧 도착. 거리는 0 이 아니라 1 이다
    t.check(solution({{1}}), 1);
    // 경계 ② 한 줄짜리 일직선 통로
    t.check(solution({{1,1,1,1,1}}), 5);
    // 경계 ③ 도착점 자체가 벽
    t.check(solution({{1,1},{1,0}}), -1);
    // 경계 ④ 직선으로 못 가고 우회해야 하는 경우
    t.check(solution({{1,1,1},{0,0,1},{1,1,1}}), 5);
    return t.report();
}
