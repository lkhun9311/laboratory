// https://school.programmers.co.kr/learn/courses/30/lessons/76502?language=cpp
// 출처: 월간 코드 챌린지 시즌2
// 대응 Python 풀이: ../../Python/LV2/!106_괄호_회전하기.py

// Number of times solving questions: 1
// 2026-09-20
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> dq(s.begin(), s.end());
    int n = s.size();
    unordered_map<char, int> char_closed_map{
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (int i=0 ; i<n; i++) {
        stack<char> s_stack;
        bool is_closed = true;

        for (char ch : dq) {
            if (
                ch == '(' ||
                ch == '{' ||
                ch == '['
            ) {
                s_stack.push(ch);
            } else {
                if (s_stack.empty()) {
                    is_closed = false;
                    break;
                }

                char s_stack_top = s_stack.top();
                if (s_stack_top == char_closed_map[ch]) {
                    s_stack.pop();
                } else {
                    is_closed = false;
                    break;
                }
            }
        }

        if (is_closed && s_stack.empty()) {
            answer++;
        }

        char dq_front = dq.front();
        dq.pop_front();
        dq.push_back(dq_front);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("[](){}"), 3);
    t.check(solution("}]()[{"), 2);
    t.check(solution("[)(]"), 0);
    t.check(solution("}}}"), 0);

    // 아래는 직접 추가한 경계 케이스 (s 길이 1~1,000)
    t.check("가장 짧은 올바른 문자열", solution("()"), 1);
    t.check("한 글자는 올바를 수 없다", solution("("), 0);
    t.check("겹쳐 있어 회전해도 안 된다", solution("([)]"), 0);
    t.check("중첩된 형태", solution("({[]})"), 1);
    t.check("세 종류가 나란히 반복", solution("()()()"), 3);
    return t.report();
}
