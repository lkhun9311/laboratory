// https://school.programmers.co.kr/learn/courses/30/lessons/12917?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!80_문자열_내림차순으로_배치하기.py

// Number of times solving questions: 1
// 2026-08-30

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

string solution(string s) {
    // 규칙. 문자를 큰 것부터 작은 순으로 정렬한다.
    //      "대문자는 소문자보다 작다"는 조건은 추가 처리를 요구하는 게 아니라
    //      문자 코드가 이미 그렇게 되어 있다는 안내다 ('A'=65 ... 'Z'=90, 'a'=97 ... 'z'=122).
    //      그래서 그냥 내림차순 정렬하면 된다.
    sort(s.begin(), s.end(), greater<char>());

    return s;
}

int main() {
    Tester t("solution");
    t.check(solution("Zbcdefg"), "gfedcbZ");
    t.check("이미 내림차순", solution("gfedcbZ"), "gfedcbZ");
    t.check("섞인 입력", solution("AbCdEf"), "fdbECA");
    t.check("대소문자 섞임", solution("zZaA"), "zaZA");
    t.check("한 글자", solution("a"), "a");
    t.check("같은 글자 반복", solution("aaa"), "aaa");
    return t.report();
}
