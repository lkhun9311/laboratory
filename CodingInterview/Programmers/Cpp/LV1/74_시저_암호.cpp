// https://school.programmers.co.kr/learn/courses/30/lessons/12926?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!74_시저_암호.py

// Number of times solving questions: 1
// 2026-09-01

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

string solution(string s, int n) {
    // 규칙 1. 각 알파벳을 n칸 뒤로 민다. 공백은 아무리 밀어도 공백이다.
    // 규칙 2. 알파벳 끝을 넘으면 처음으로 돌아온다 (z + 1 = a, Z + 1 = A).
    //        n이 최대 25라 한 바퀴 이상 돌지 않으므로 26을 한 번만 빼면 된다.
    // 참고. 대문자와 소문자는 코드 구간이 다르다 (A~Z = 65~90, a~z = 97~122).
    //      C++ 에서 char 는 그 자체가 숫자라 ord/chr 같은 변환 함수가 필요 없다.
    string answer = "";

    // string 을 순회하면 원소는 string 이 아니라 char 다.
    for (char letter : s) {
        if (letter == ' ') {
            answer += ' ';
            continue;
        }

        int shifted = letter + n;   // char + int -> int 로 계산된다

        if ('a' <= letter && letter <= 'z' && shifted > 'z') {
            shifted -= 26;
        }

        if ('A' <= letter && letter <= 'Z' && shifted > 'Z') {
            shifted -= 26;
        }

        // string 의 += 는 char 를 직접 받는다 (생성자로는 char 하나를 못 받는다).
        answer += (char)shifted;
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("AB", 1), "BC");
    t.check(solution("z", 1), "a");
    t.check(solution("a B z", 4), "e F d");
    t.check("대문자 순환", solution("Z", 1), "A");
    t.check("최대 이동 25", solution("AaZz", 25), "ZzYy");
    t.check("공백만", solution("   ", 3), "   ");
    return t.report();
}
