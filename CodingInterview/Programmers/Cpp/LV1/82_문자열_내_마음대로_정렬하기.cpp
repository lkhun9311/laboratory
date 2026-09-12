// https://school.programmers.co.kr/learn/courses/30/lessons/12915?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/82_문자열_내_마음대로_정렬하기.py

// Number of times solving questions: 1
// 2026-09-12

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>    // sort. 스켈레톤에 없으므로 직접 추가한다
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    // 규칙 1. 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬한다.
    // 규칙 2. n번째 글자가 같으면 그들끼리는 사전순으로 놓는다.
    // 규칙 3. 모든 원소의 길이가 n보다 크다는 것이 보장되므로 범위 검사가 필요 없다.

    // 매개변수 strings 는 이미 호출자 값의 복사본이다.
    // 새 vector 를 만들지 않고 제자리에서 정렬해 그대로 반환한다.
    //
    // 비교 함수는 "a 가 b 보다 먼저 와야 하는가"에 답한다.
    // Python 의 sorted(key=...) 가 "무엇으로 비교할지"를 주는 것과 발상이 다르다.
    //
    // [n] 은 람다가 바깥 변수 n 을 가져다 쓴다는 표시(캡처)다. 빈 [] 로 두면 n 을 쓸 수 없다.
    sort(strings.begin(), strings.end(),
        [n](const string& a, const string& b) {
            // 1순위 기준으로 판가름이 나면 거기서 끝낸다. (규칙 1)
            // 이 모양이라 기준이 3개 이상으로 늘어도 아래에 그대로 이어 붙일 수 있다.
            if (a[n] != b[n]) {
                return a[n] < b[n];
            }

            // 1순위가 같을 때만 2순위로 넘어간다. string 끼리의 < 가 곧 사전순이다. (규칙 2)
            //
            // 여기서 <= 를 쓰면 안 된다. 같은 원소에 true 를 주면
            // sort 는 "a 가 b 보다 앞이면서 b 도 a 보다 앞"이라는 모순을 받아
            // 런타임에 터지거나 무한 루프에 빠진다. 비교 함수는 "같으면 반드시 false" 여야 한다.
            return a < b;
        }
    );

    return strings;
}

int main() {
    Tester t("solution");
    t.check(solution({"sun", "bed", "car"}, 1), vector<string>{"car", "bed", "sun"});
    t.check(solution({"abce", "abcd", "cdx"}, 2), vector<string>{"abcd", "abce", "cdx"});

    // 아래는 직접 추가한 경계 케이스
    t.check("원소 1개", solution({"abc"}, 0), vector<string>{"abc"});
    t.check("n = 0", solution({"cba", "bca", "abc"}, 0), vector<string>{"abc", "bca", "cba"});
    t.check("기준 글자가 전부 같음 -> 사전순",
            solution({"xbc", "xab", "xaa"}, 0), vector<string>{"xaa", "xab", "xbc"});
    t.check("완전히 같은 문자열 포함",
            solution({"abc", "abc", "abd"}, 2), vector<string>{"abc", "abc", "abd"});
    return t.report();
}
