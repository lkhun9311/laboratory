// https://school.programmers.co.kr/learn/courses/30/lessons/250121?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!11_데이터_분석.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> filteredData;
    unordered_map<string, int> columnIndex{
        {"code", 0},
        {"date", 1},
        {"maximum", 2},
        {"remain", 3}
    };

    int filterColumnIndex = columnIndex[ext];
    for (const vector<int>& d: data) {
        if (d[filterColumnIndex] < val_ext) {
            filteredData.push_back(d);
        }
    }

    int sortColumnIndex = columnIndex[sort_by];
    sort(
        filteredData.begin(),
        filteredData.end(),
        [sortColumnIndex](const vector<int>& a, const vector<int>& b) {
            return a[sortColumnIndex] < b[sortColumnIndex];
        }
    );

    return filteredData;
}

int main() {
    Tester t("solution");
    t.check(solution({{1, 20300104, 100, 80}, {2, 20300804, 847, 37}, {3, 20300401, 10, 8}},
                     "date", 20300501, "remain"),
            vector<vector<int>>{{3, 20300401, 10, 8}, {1, 20300104, 100, 80}});

    // 아래는 직접 추가한 경계 케이스
    t.check("행 하나, 조건 통과", solution({{1, 20300104, 100, 80}}, "code", 2, "maximum"),
            vector<vector<int>>{{1, 20300104, 100, 80}});
    t.check("아무 행도 통과하지 못한다 — 빈 결과",
            solution({{1, 20300104, 100, 80}}, "code", 1, "maximum"),
            vector<vector<int>>{});
    t.check("경계값은 통과하지 못한다 (< 이므로 같은 값 제외)",
            solution({{5, 20300104, 100, 80}}, "code", 5, "code"),
            vector<vector<int>>{});
    t.check("code 로 정렬",
            solution({{3, 1, 1, 1}, {1, 2, 2, 2}, {2, 3, 3, 3}}, "maximum", 100, "code"),
            vector<vector<int>>{{1, 2, 2, 2}, {2, 3, 3, 3}, {3, 1, 1, 1}});
    t.check("maximum 으로 정렬하며 일부만 걸러진다",
            solution({{1, 1, 50, 9}, {2, 2, 10, 8}, {3, 3, 90, 7}}, "remain", 9, "maximum"),
            vector<vector<int>>{{2, 2, 10, 8}, {3, 3, 90, 7}});
    return t.report();
}
