// https://school.programmers.co.kr/learn/courses/30/lessons/70129?language=cpp
// 출처: 월간 코드 챌린지 시즌1
// 대응 Python 풀이: ../../Python/LV2/!22_이진_변환_반복하기.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int time = 0;
    int deleted_0 = 0;

    while (s != "1") {
        int count_1 = count(s.begin(), s.end(), '1');
        int count_0 = count(s.begin(), s.end(), '0');
        deleted_0 += count_0;

        string binary;
        while (count_1>0) {
            binary += (count_1%2) + '0';
            count_1 /= 2;
        }

        reverse(binary.begin(), binary.end());
        s = binary;
        time++;
    }

    return {time, deleted_0};
}

int main() {
    Tester t("solution");
    t.check(solution("110010101001"), vector<int>{3, 8});
    t.check(solution("01110"), vector<int>{3, 3});
    t.check(solution("1111111"), vector<int>{4, 1});

    // 아래는 직접 추가한 경계 케이스
    t.check("이미 \"1\" — 한 번도 변환하지 않는다", solution("1"), vector<int>{0, 0});
    t.check("\"10\" 한 번에 끝난다", solution("10"), vector<int>{1, 1});
    t.check("\"11\" -> \"10\" -> \"1\"", solution("11"), vector<int>{2, 1});
    t.check("0 이 앞에 잔뜩", solution("000001"), vector<int>{1, 5});
    return t.report();
}
