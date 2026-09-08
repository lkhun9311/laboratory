// https://school.programmers.co.kr/learn/courses/30/lessons/12930?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/72_이상한_문자_만들기.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <cctype>       // toupper, tolower
using namespace std;

string solution(string s) {
    // 규칙 1. 각 단어에서 짝수번째 글자는 대문자, 홀수번째는 소문자로 바꾼다.
    // 규칙 2. 인덱스는 단어마다 0부터 다시 센다.
    // 규칙 3. 공백은 원래 자리에 그대로 두며, 연속 공백도 개수까지 보존한다.

    // 문자열을 단어로 쪼개지 않고, 카운터 하나를 들고 한 번만 훑는다.
    // 쪼개는 방식(stringstream + getline)은 join을 직접 짜야 하고,
    // 무엇보다 getline이 "문자열이 구분자로 끝날 때 마지막 빈 조각을 만들지 않아"
    // 끝 공백이 사라진다(Python split(" ")과 다른 점). 쪼개지 않으면 그 함정이 아예 생기지 않는다.
    int index = 0;

    // 매개변수 s는 이미 호출자 값의 복사본이므로, 새 문자열을 만들지 않고 제자리에서 고친다.
    // char&(참조)로 받아야 대입이 s에 반영된다. char로 받으면 사본이라 원본이 안 바뀐다.
    for (char& ch : s) {
        // 공백은 손대지 않고 카운터만 0으로 되돌린다.
        // 그러면 "단어마다 인덱스 리셋"이 저절로 처리되고 (규칙 2),
        // 공백을 지우지 않으므로 연속 공백도 개수 그대로 남는다. (규칙 3)
        if (ch == ' ') {
            index = 0;
            continue;
        }

        // toupper/tolower는 int를 반환하므로 char로 명시적으로 되돌린다. (규칙 1)
        ch = (char)(index % 2 == 0 ? toupper(ch) : tolower(ch));
        index++;
    }

    return s;
}

int main() {
    Tester t("solution");
    t.check(solution("try hello world"), string("TrY HeLlO WoRlD"));

    // 아래는 직접 추가한 경계 케이스
    t.check("연속 공백", solution("ab  cd"), string("Ab  Cd"));
    t.check("앞 공백", solution(" abc"), string(" AbC"));
    t.check("끝 공백", solution("abc "), string("AbC "));
    t.check("끝 공백 2개", solution("x  "), string("X  "));
    t.check("공백만", solution("  "), string("  "));
    t.check("한 글자", solution("a"), string("A"));
    t.check("대소문자 섞임", solution("AbC  dEf   g"), string("AbC  DeF   G"));
    return t.report();
}
