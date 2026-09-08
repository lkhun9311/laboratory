// https://school.programmers.co.kr/learn/courses/30/lessons/12918?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/79_문자열_다루기_기본.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
using namespace std;

bool solution(string s) {
    // 규칙 1. 문자열 s의 길이가 4 또는 6이어야 한다.
    // 규칙 2. 그리고 s가 전부 숫자(0~9)여야 한다. 둘 다 만족할 때만 true.

    int s_size = s.size();

    // 길이가 틀리면 글자를 한 개도 볼 필요가 없다. 루프 앞에서 끝낸다. (규칙 1)
    // 이 검사를 루프 안에 두면 매 글자마다 같은 판정을 반복하고,
    // 빈 문자열일 때 루프가 0번 돌아 검사 자체가 실행되지 않는다.
    if (s_size != 4 && s_size != 6) {
        return false;
    }

    // "전부 숫자"는 하나라도 아니면 거짓이므로, 반례를 찾는 순간 종료한다. (규칙 2)
    // char는 내부적으로 숫자값이고 '0'~'9'가 연속이라 부등호로 범위를 판정할 수 있다.
    // isdigit 대신 이 방식을 쓰면 헤더 추가가 필요 없고 ASCII 0~9만임이 코드에 드러난다.
    for (char i : s) {
        if (i < '0' || i > '9') {
            return false;
        }
    }

    return true;
}

int main() {
    Tester t("solution");
    t.check(solution("a234"), false);
    t.check(solution("1234"), true);

    // 아래는 직접 추가한 경계 케이스
    t.check("길이 6 전부 숫자", solution("123456"), true);
    t.check("길이 5 전부 숫자", solution("12345"), false);
    t.check("길이 1", solution("1"), false);
    t.check("길이 8 전부 숫자", solution("12345678"), false);
    t.check("길이는 맞고 문자 섞임", solution("12a4"), false);
    return t.report();
}
