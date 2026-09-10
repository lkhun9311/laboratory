// https://school.programmers.co.kr/learn/courses/30/lessons/131128?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/32_숫자_짝꿍.py

// Number of times solving questions: 1
// 2026-09-10

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>    // min
using namespace std;

string solution(string X, string Y) {
    // 규칙 1. X 와 Y 에 "공통으로" 나타나는 숫자들로 만들 수 있는 가장 큰 수를 반환한다.
    //         공통 개수는 양쪽 등장 횟수의 min 이다 (X="5525", Y="1255" 에서 5 는 3개와 2개 -> 2개).
    // 규칙 2. 공통 숫자가 하나도 없으면 "-1".
    // 규칙 3. 답이 0 들뿐이면 "000"이 아니라 "0" 하나만.
    // 규칙 4. X, Y 길이가 최대 3,000,000 -> 정렬(O(n log n))도 부담이다. O(n) 으로 간다.

    // 숫자는 0~9 열 가지뿐이므로 등장 횟수만 세면 된다. 문자열을 정렬할 이유가 없다. (규칙 4)
    // 크기가 고정이라 vector 대신 일반 배열로 충분하다.
    int count_x[10] = {0};
    int count_y[10] = {0};

    // '7' - '0' == 7. 문자 코드가 '0'~'9' 순으로 연속이라 성립한다.
    for (char c : X) count_x[c - '0']++;
    for (char c : Y) count_y[c - '0']++;

    string result;

    // 큰 자릿수를 앞에 놓아야 수가 커지므로 9 부터 내려온다.
    // 공통 개수만큼 그 숫자를 붙이면 그것이 곧 가능한 최댓값이다. (규칙 1)
    result.reserve(min(X.size(), Y.size()));

    for (int d = 9; d >= 0; d--) {
        int cnt = min(count_x[d], count_y[d]);
        if (cnt > 0) {
            // append(n, c) 는 문자 c 를 n 개 한 번에 붙인다.
            // to_string(d) 를 cnt 번 부르면 매번 임시 문자열이 생긴다.
            // char('0' + d) 는 위 c - '0' 의 정확한 역방향이다.
            // 실측(각 300만자): 하나씩 5.6ms -> 한 번에 2.0ms
            result.append(cnt, (char)('0' + d));
        }
    }

    // 공통 숫자가 하나도 없었다는 뜻. (규칙 2)
    if (result.empty()) {
        return "-1";
    }

    // 9 부터 내려왔으므로 첫 글자가 '0' 이면 나머지도 전부 '0' 이다. (규칙 3)
    if (result[0] == '0') {
        return "0";
    }

    return result;
}

int main() {
    Tester t("solution");
    t.check(solution("100", "2345"), string("-1"));
    t.check(solution("100", "203"), string("0"));
    t.check(solution("233", "2333"), string("332"));
    t.check(solution("12321", "42531"), string("321"));
    t.check(solution("5525", "1255"), string("552"));

    // 아래는 직접 추가한 경계 케이스
    t.check("0만 공통", solution("000", "0000"), string("0"));
    t.check("전부 공통", solution("999", "999"), string("999"));
    t.check("0이 섞였지만 답은 0이 아님", solution("102", "021"), string("210"));
    return t.report();
}
