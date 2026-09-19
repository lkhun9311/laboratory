// https://school.programmers.co.kr/learn/courses/30/lessons/43165?language=cpp
// 출처: 깊이/너비 우선 탐색(DFS/BFS)
// 대응 Python 풀이: ../../Python/LV2/!42_타겟_넘버.py

// Number of times solving questions: 1
// 2026-09-19
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int index, int current_sum) {
    int n = numbers.size();
    if (n == index) {
        return target == current_sum ? 1 : 0;
    }

    int plus_count = dfs(
        numbers,
        target,
        index+1,
        current_sum + numbers[index]
    );

    int minus_count = dfs(
        numbers,
        target,
        index+1,
        current_sum - numbers[index]
    );

    return plus_count + minus_count;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}

int main() {
    Tester t("solution");
    t.check(solution({1, 1, 1, 1, 1}, 3), 5);
    t.check(solution({4, 1, 2, 1}, 4), 2);

    // 아래는 직접 추가한 경계 케이스 (numbers 길이 2~20, 원소 1~50, target 1~1000)
    t.check("가장 짧은 입력 — 전부 더해야 한다", solution({1, 1}, 2), 1);
    t.check("도달할 수 없는 target", solution({1, 1}, 5), 0);
    t.check("하나만 빼면 되는 경우 (4C1)", solution({1, 1, 1, 1}, 2), 4);
    t.check("최대 길이 20, 전부 더해야 target 1000", solution(vector<int>(20, 50), 1000), 1);
    return t.report();
}
