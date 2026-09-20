// https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp
// 출처: 완전탐색
// 대응 Python 풀이: ../../Python/LV2/!40_피로도.py

// Number of times solving questions: 1
// 2026-09-20
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
/*
k: 현재 피로도
dungeons: [[최소 필요 피로도, 소모 피로도]]
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(
    int currentCount,
    int k,
    vector<vector<int>>& dungeons,
    vector<bool>& visited
) {
    int dungeonCount = dungeons.size();
    int maxCount = currentCount;

    for (int i = 0; i < dungeonCount; i++) {
        if (visited[i]) {
            continue;
        }

        int requiredFatigue = dungeons[i][0];
        int consumedFatigue = dungeons[i][1];

        if (k < requiredFatigue) {
            continue;
        }

        visited[i] = true;
        int exploredCount = dfs(
            currentCount+1,
            k-consumedFatigue,
            dungeons,
            visited
        );
        visited[i] = false;

        maxCount = max(maxCount, exploredCount);
    }

    return maxCount;
}

int solution(int k, vector<vector<int>> dungeons) {
    int dungeonCount = dungeons.size();
    int currentCount = 0;
    vector<bool> visited(dungeonCount, false);
    return dfs(currentCount, k, dungeons, visited);
}

int main() {
    Tester t("solution");
    t.check(solution(80, {{80, 20}, {50, 40}, {30, 10}}), 3);

    // 아래는 직접 추가한 경계 케이스 (던전 1~8개, k 1~5000)
    t.check("던전 하나, 들어갈 수 있다", solution(10, {{10, 5}}), 1);
    t.check("던전 하나, 피로도 부족", solution(5, {{10, 5}}), 0);
    t.check("순서를 바꿔야 둘 다 들어간다", solution(30, {{20, 20}, {30, 10}}), 2);
    t.check("최대 8개 전부 탐험", solution(8, {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}}), 8);
    t.check("소모는 적지만 요구가 커서 하나만", solution(10, {{10, 1}, {20, 1}}), 1);
    return t.report();
}
