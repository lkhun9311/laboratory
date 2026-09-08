// https://school.programmers.co.kr/learn/courses/30/lessons/12930?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/72_이상한_문자_만들기.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <cctype>       // toupper, tolower
#include <sstream>      // stringstream. 헤더 이름은 <stringstream>이 아니다
using namespace std;

string solution(string s) {
    // 규칙 1. 각 단어에서 짝수번째 글자는 대문자, 홀수번째는 소문자로 바꾼다.
    // 규칙 2. 인덱스는 단어마다 0부터 다시 센다.
    // 규칙 3. 공백은 원래 자리에 그대로 두며, 연속 공백도 개수까지 보존한다.

    string answer = "";
    vector<string> converted_words;
    stringstream ss(s);
    string word;

    // 구분자를 ' '로 명시한 getline은 연속 공백 사이의 빈 조각을 그대로 남긴다.
    // ss >> word 를 쓰면 연속 공백을 합쳐버려 오답이 된다 (Python의 인자 없는 split()과 같은 함정). (규칙 3)
    // getline은 조각을 하나씩 읽고 스트림을 반환하므로 while로 돈다.
    while (getline(ss, word, ' ')) {
        // 단어 단위로 index를 새로 0부터 세므로 "단어마다 리셋"이 저절로 처리된다. (규칙 2)
        // C++에는 enumerate가 없어 카운터를 직접 증가시킨다.
        int index = 0;
        string converted = "";

        for (char ch : word) {
            if (index%2 == 0) {
                char up = toupper(ch);      // toupper는 int를 반환하므로 char로 받아둔다
                converted += up;
            } else {
                char lower = tolower(ch);
                converted += lower;
            }
            index++;
        }

        converted_words.push_back(converted);
    }

    // C++에는 join이 없어 직접 이어붙인다.
    // 구분자를 "각 원소 뒤"가 아니라 "첫 번째를 제외한 각 원소 앞"에 넣어야 끝에 여분이 생기지 않는다.
    int n = converted_words.size();
    for (int i=0; i<n; i++) {
        if (i>0) {
            answer += ' ';
        }
        answer += converted_words[i];
    }

    // getline은 문자열이 구분자로 끝날 때 마지막 빈 조각을 만들지 않는다 (Python split(" ")과 다른 점).
    // 항상 정확히 하나가 모자라므로, 끝이 공백이면 공백 하나를 되돌려 놓는다. (규칙 3)
    // s의 길이가 1 이상임이 보장되므로 back() 호출은 안전하다.
    if (s.back() == ' ') {
        answer += ' ';
    }

    return answer;
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
