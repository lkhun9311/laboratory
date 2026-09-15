// https://school.programmers.co.kr/learn/courses/30/lessons/17681?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!55_1차_비밀지도.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int arr_size = arr1.size();

    for (int i=0; i<arr_size; i++) {
        int merged = arr1[i] | arr2[i];
        string row;

        for (int j=n-1; j>=0; j--) {
            if((merged >> j) & 1) {
                row += '#';
            } else {
                row += ' ';
            }
        }
        answer.push_back(row);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28}),
            vector<string>{"#####", "# # #", "### #", "#  ##", "#####"});
    t.check(solution(6, {46, 33, 33, 22, 31, 50}, {27, 56, 19, 14, 14, 10}),
            vector<string>{"######", "###  #", "##  ##", " #### ", " #####", "### # "});

    // 아래는 직접 추가한 경계 케이스
    t.check("최소 n=1, 벽 없음", solution(1, {0}, {0}), vector<string>{" "});
    t.check("최소 n=1, 벽 있음", solution(1, {1}, {0}), vector<string>{"#"});
    t.check("앞자리 0 이 공백으로 남는다", solution(5, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}),
            vector<string>{"     ", "     ", "     ", "     ", "    #"});
    t.check("최대 n=16, 전부 벽", solution(16, vector<int>(16, 65535), vector<int>(16, 0)),
            vector<string>(16, string(16, '#')));
    t.check("최대 n=16, 맨 왼쪽 비트만", solution(16, vector<int>(16, 32768), vector<int>(16, 0)),
            vector<string>(16, "#" + string(15, ' ')));
    return t.report();
}
