// https://school.programmers.co.kr/learn/courses/30/lessons/81301?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!39_숫자_문자열과_영단어.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<string, int> number_map{
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    string bucket = "";
    for (char ch : s) {
        if ('0' <= ch and ch <= '9') {
            answer = (answer*10) + (ch-'0');
        } else {
            bucket += ch;
        }

        if (number_map.find(bucket) != number_map.end()) {
            answer = (answer*10) + number_map[bucket];
            bucket = "";
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("one4seveneight"), 1478);
    t.check(solution("23four5six7"), 234567);
    t.check(solution("2three45sixseven"), 234567);
    t.check(solution("123"), 123);

    // 아래는 직접 추가한 경계 케이스
    t.check("한 글자", solution("7"), 7);
    t.check("한 단어", solution("nine"), 9);
    t.check("0 이 중간에 섞임", solution("1zero0zero"), 1000);
    t.check("최댓값 2,000,000,000 을 숫자로", solution("2000000000"), 2000000000);
    t.check("최댓값 2,000,000,000 을 전부 영단어로",
            solution("twozerozerozerozerozerozerozerozerozero"), 2000000000);
    return t.report();
}
