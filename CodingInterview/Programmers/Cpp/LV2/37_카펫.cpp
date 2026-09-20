// https://school.programmers.co.kr/learn/courses/30/lessons/42842?language=cpp
// 출처: 완전탐색
// 대응 Python 풀이: ../../Python/LV2/!37_카펫.py

// Number of times solving questions: 1
// 2026-09-20
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    int new_y_h = 0;
    int new_y_w = 0;

    for (int y=1; y*y<=yellow; y++) {
        int y_share = 0;
        int y_remain = yellow%y;

        if (y_remain == 0) {
            y_share = yellow/y;
        }

        new_y_h = y_share+2;
        new_y_w = y+2;
        int new_y_area = new_y_h * new_y_w;
        if (total == new_y_area) {
            break;
        }
    }

    return {new_y_h, new_y_w};
}

int main() {
    Tester t("solution");
    t.check(solution(10, 2), vector<int>{4, 3});
    t.check(solution(8, 1), vector<int>{3, 3});
    t.check(solution(24, 24), vector<int>{8, 6});

    // 아래는 직접 추가한 경계 케이스 (brown 8~5000, yellow 1~2,000,000)
    t.check("가장 작은 카펫", solution(8, 1), vector<int>{3, 3});
    // 노란 1x5 격자면 카펫은 3x7 이므로 total 21, brown 은 16 이다 (brown 14 는 존재할 수 없는 입력)
    t.check("노란 격자가 한 줄", solution(16, 5), vector<int>{7, 3});
    t.check("정사각형", solution(16, 4), vector<int>{4, 4});
    t.check("세로로 긴 노란 격자", solution(18, 10), vector<int>{7, 4});
    return t.report();
}
