// https://school.programmers.co.kr/learn/courses/30/lessons/12973?language=cpp
// 출처: 2017 팁스타운
// 대응 Python 풀이: ../../Python/LV2/!07_짝지어_제거하기.py

// Number of times solving questions: 1
// 2026-09-19
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    string temp_s;

    for (char ch : s) {
        if (!temp_s.empty() && temp_s.back() == ch) {
            temp_s.pop_back();
        } else {
            temp_s.push_back(ch);
        }
    }

    return temp_s.size() == 0;
}

int main() {
    Tester t("solution");
    t.check(solution("baabaa"), 1);
    t.check(solution("cdcd"), 0);

    // 아래는 직접 추가한 경계 케이스
    t.check("한 글자 — 짝이 없다", solution("a"), 0);
    t.check("같은 글자 두 개", solution("aa"), 1);
    t.check("짝이 두 쌍", solution("aabb"), 1);
    t.check("안쪽부터 터진다 (abba)", solution("abba"), 1);
    t.check("홀수 길이는 항상 0", solution("aaa"), 0);
    return t.report();
}
