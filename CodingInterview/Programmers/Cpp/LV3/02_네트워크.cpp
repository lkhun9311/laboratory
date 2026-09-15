// https://school.programmers.co.kr/learn/courses/30/lessons/43162?language=cpp
// 출처: 깊이/너비 우선 탐색(DFS/BFS)
// 대응 Python 풀이: ../../Python/LV3/02_네트워크.py

// Number of times solving questions: 1
// 2026-09-15

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <queue>
using namespace std;

// 규칙 1. computers[i][j] == 1 이면 i 와 j 가 직접 연결돼 있다.
// 규칙 2. 직접이든 건너서든 이어져 있으면 같은 네트워크다.
// 규칙 3. 네트워크가 몇 개인지 돌려준다.
//
// 01번 컬러링북과 세는 것이 똑같다 — 덩어리가 몇 개인가.
// 격자가 아니라는 것 하나만 다르고, 그 차이는 "이웃을 어떻게 구하느냐"로만 나타난다.
//
//   격자였을 때                        여기
//   ─────────────────────────          ─────────────────────────
//   칸 (r, c)                          컴퓨터 번호 i
//   상하좌우 4방향 dr/dc               computers[i][j] == 1 인 모든 j
//   0 <= nr < n 범위 검사 필요          j 가 이미 0..n-1 이라 불필요
//   visited[r][c]  2차원               visited[i]  1차원
//
// 나머지 뼈대는 그대로다.
//   바깥 루프 : 아직 안 가 본 정점을 찾는다 → 새 네트워크의 시작점
//   안쪽 BFS  : 거기서 닿는 곳을 전부 visited 로 칠한다
//   따라서 바깥 루프에서 BFS 를 시작한 횟수 = 네트워크 개수
//
// computers[i][i] 는 항상 1 이지만(자기 자신) 따로 처리할 필요가 없다.
// 그 시점에 visited[i] 가 이미 켜져 있어 조건에서 걸러진다.
//
// visited 를 함수 안에서 만든다. 밖에서 만들어 넘기면 값으로 받을지 참조로 받을지를
// 고민해야 하는데, 값으로 받으면 변경이 호출한 쪽에 남지 않아 조용히 틀린다.
// 넘기지 않으면 그 함정 자체가 없다.
int count_networks(int n, const vector<vector<int>>& computers) {
    int count = 0;
    vector<bool> visited(n, false);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;  // 이미 어떤 네트워크에 속한 컴퓨터

        count++;                   // 여기서 시작하는 네트워크가 하나 더 있다
        q.push(i);
        visited[i] = true;         // 넣을 때 켠다

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                if (computers[current][j] == 1 && !visited[j]) {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> computers) {
    return count_networks(n, computers);
}

int main() {
    Tester t("solution");
    t.check(solution(3, {{1,1,0},{1,1,0},{0,0,1}}), 2);
    t.check(solution(3, {{1,1,0},{1,1,1},{0,1,1}}), 1);
    // 경계 ① 컴퓨터 1대
    t.check(solution(1, {{1}}), 1);
    // 경계 ② 전부 따로 떨어져 있다
    t.check(solution(4, {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}), 4);
    // 경계 ③ 전부 하나로 묶여 있다
    t.check(solution(4, {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}}), 1);
    // 경계 ④ 사슬 연결 — 0-1-2-3. 직접 연결은 인접끼리뿐이지만 한 네트워크다
    t.check(solution(4, {{1,1,0,0},{1,1,1,0},{0,1,1,1},{0,0,1,1}}), 1);
    return t.report();
}
