// https://school.programmers.co.kr/learn/courses/30/lessons/12903?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/86_가운데_글자_가져오기.py

// Number of times solving questions: 1
// 2026-08-22

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string solution(string s) {
    string answer = "";
    int size_of_s = s.size();
    int mid = size_of_s / 2;
    if (size_of_s % 2 == 0) {
        answer = s.substr(mid-1, 2);
    } else {
        answer = s[mid];
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("abcde"), "c");
    t.check(solution("qwer"), "we");
    t.check("긴 홀수", solution("abcdefg"), "d");
    t.check("긴 짝수", solution("abcdef"), "cd");
    t.check("한 글자", solution("a"), "a");
    t.check("두 글자", solution("ab"), "ab");
    t.check("100자 짝수", solution(string(49, 'x') + "AB" + string(49, 'y')), "AB");
    t.check("99자 홀수", solution(string(49, 'x') + "M" + string(49, 'y')), "M");
    return t.report();
}
