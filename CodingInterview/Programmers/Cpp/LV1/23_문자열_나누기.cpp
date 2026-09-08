// https://school.programmers.co.kr/learn/courses/30/lessons/140108?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/23_문자열_나누기.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
using namespace std;

int solution(string s) {
    // 규칙 1. 첫 글자를 기준 문자로 정하고, 기준과 같은 글자 수와 다른 글자 수를 센다.
    // 규칙 2. 두 개수가 같아지는 순간 거기까지 한 덩어리로 자르고, 다음 글자부터 다시 규칙 1.
    // 규칙 3. 끝까지 두 개수가 같아지지 않으면 남은 부분도 한 덩어리로 센다.

    int answer = 0;

    // "같은 개수 == 다른 개수" 는 "두 수의 차이가 0" 과 같다.
    // 그래서 카운터를 둘 들 필요 없이, 같으면 +1 다르면 -1 인 차이 하나만 들고 0인지 보면 된다.
    // (괄호 짝 맞추기, 보이어-무어 다수결도 같은 패턴)
    int cnt = 0;

    // 담는 것이 글자 하나이므로 string이 아니라 char다.
    // cnt == 0 인 첫 글자에서 반드시 대입되므로 초깃값 자체는 쓰이지 않는다.
    char base = 0;

    for (char ch : s) {
        // cnt == 0 은 "직전 덩어리가 끝나고 새 덩어리가 시작된다"는 뜻이다. (규칙 2)
        // 덩어리를 "끝날 때"가 아니라 "시작할 때" 세는 것이 핵심이다.
        // 끝까지 균형이 맞지 않는 마지막 덩어리도 시작 시점에 이미 세어졌으므로,
        // 루프 뒤에 남은 덩어리를 따로 처리하는 코드가 필요 없다. (규칙 3)
        if (cnt == 0) {
            base = ch;
            answer += 1;
        }

        if (base == ch) {
            cnt += 1;
        } else {
            cnt -= 1;
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("banana"), 3);
    t.check(solution("abracadabra"), 6);
    t.check(solution("aaabbaccccabba"), 3);

    // 아래는 직접 추가한 경계 케이스
    t.check("한 글자", solution("a"), 1);
    t.check("끝이 균형 안 맞음", solution("abc"), 2);
    t.check("전부 같은 글자", solution("aaa"), 1);
    t.check("마지막 덩어리 미완성", solution("aab"), 1);
    return t.report();
}
