// https://school.programmers.co.kr/learn/courses/30/lessons/12950?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!60_행렬의_덧셈.py

// Number of times solving questions: 1
// 2026-08-29

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // 규칙. 같은 크기의 두 행렬을 같은 자리끼리 더한다.
    //      결과를 미리 만들지 않고 한 행씩 완성해 붙이면 크기 계산 실수가 없다.
    vector<vector<int>> answer;

    int arr_row_size = arr1.size();
    int arr_col_size = arr1[0].size();     // arr1[0] 자체가 vector<int> 이므로 다시 size()

    for (int i = 0; i < arr_row_size; i++) {
        vector<int> row;
        for (int j = 0; j < arr_col_size; j++) {
            row.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(row);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({{1,2},{2,3}}, {{3,4},{5,6}}), vector<vector<int>>{{4,6},{7,9}});
    t.check(solution({{1},{2}}, {{3},{4}}), vector<vector<int>>{{4},{6}});
    t.check("1행 3열", solution({{1,2,3}}, {{4,5,6}}), vector<vector<int>>{{5,7,9}});
    t.check("3행 1열", solution({{1},{2},{3}}, {{10},{20},{30}}), vector<vector<int>>{{11},{22},{33}});
    t.check("1x1", solution({{7}}, {{8}}), vector<vector<int>>{{15}});
    return t.report();
}
