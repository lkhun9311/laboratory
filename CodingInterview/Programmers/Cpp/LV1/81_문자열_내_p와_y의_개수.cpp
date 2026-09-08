// https://school.programmers.co.kr/learn/courses/30/lessons/12916?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/81_문자열_내_p와_y의_개수.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
using namespace std;

bool solution(string s) {
    // 규칙 1. s에서 'p'와 'y'의 개수를 세어 같으면 true, 다르면 false.
    // 규칙 2. 대소문자는 구분하지 않는다 ('P'와 'p'를 같게 친다).
    // 규칙 3. p와 y가 하나도 없으면 0 == 0 이므로 true.

    int p_size = 0;
    int y_size = 0;

    // 한 번의 순회로 둘을 동시에 센다.
    // Python 풀이는 lower() 한 번 + count() 두 번으로 문자열을 세 번 훑고 새 문자열도 만들지만,
    // 직접 루프를 쓰면 한 번만 훑고 공간도 O(1)이 된다.
    // 대소문자 통일은 tolower 대신 두 글자를 직접 비교한다 — 헤더가 필요 없고 의도가 그대로 보인다. (규칙 2)
    for (char i : s) {
        if (i == 'p' || i == 'P') {
            p_size += 1;
        }
        if (i == 'y' || i == 'Y') {
            y_size += 1;
        }
    }

    // 비교 결과를 그대로 반환한다. if 분기를 만들면 "둘 다 0개" 경계를 따로 처리하고 싶어지는데,
    // 0 == 0 이 이미 true라 그 분기는 불필요하고, 실제로 그 분기에서 버그가 났었다. (규칙 3)
    return p_size == y_size;
}

int main() {
    Tester t("solution");
    t.check(solution("pPoooyY"), true);
    t.check(solution("Pyy"), false);

    // 아래는 직접 추가한 경계 케이스
    t.check("p도 y도 없음", solution("abc"), true);
    t.check("대문자 p만", solution("PP"), false);
    t.check("대문자 y만", solution("YY"), false);
    t.check("한 글자 P", solution("P"), false);
    t.check("대소문자 섞여 동수", solution("pYPy"), true);
    return t.report();
}
