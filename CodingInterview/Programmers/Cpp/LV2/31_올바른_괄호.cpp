// https://school.programmers.co.kr/learn/courses/30/lessons/12909?language=cpp
// 출처: 스택/큐
// 대응 Python 풀이: ../../Python/LV2/!31_올바른_괄호.py

// Number of times solving questions: 1
// 2026-09-19
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int calS = 0;

    for (const auto& ch : s) {
        if (ch == '(') {
            calS += 1;
        }

        if (ch == ')') {
            calS -= 1;
        }

        if (calS < 0) {
            return false;
        }
    }

    return calS == 0;
}

int main() {
    Tester t("solution");
    t.check(solution("()()"), true);
    t.check(solution("(())()"), true);
    t.check(solution(")()("), false);
    t.check(solution("(()("), false);

    // 아래는 직접 추가한 경계 케이스
    t.check("가장 짧은 올바른 괄호", solution("()"), true);
    t.check("열기만 하나", solution("("), false);
    t.check("닫기만 하나", solution(")"), false);
    t.check("깊게 중첩", solution("((((()))))"), true);
    t.check("개수는 같지만 순서가 틀림", solution("())("), false);
    return t.report();
}
