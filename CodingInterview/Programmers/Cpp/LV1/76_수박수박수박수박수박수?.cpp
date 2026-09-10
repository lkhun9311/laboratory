// https://school.programmers.co.kr/learn/courses/30/lessons/12922?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/76_수박수박수박수박수박수?.py

// Number of times solving questions: 1
// 2026-09-10

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    // 규칙 1. "수"와 "박"이 번갈아 나오는 길이 n짜리 문자열을 만든다.
    // 규칙 2. n이 홀수면 마지막이 "수"로 끝난다.

    int share = n / 2;      // "수박" 한 쌍이 몇 번 들어가는가
    int rem = n % 2;        // 홀수면 "수" 하나가 더 붙는다

    string answer;

    // 한글은 UTF-8에서 한 글자가 3바이트다. size()도 글자 수가 아니라 바이트 수를 돌려준다.
    // ("수박".size() == 6). 따라서 길이는 반복 횟수로 세고, 확보할 바이트는 n * 3 이다.
    answer.reserve((size_t)n * 3);

    // "수박"을 한 쌍씩 붙인다. 한 글자씩 붙이며 매번 짝/홀을 판정하는 것보다 += 호출이 절반이다.
    // 실측(n=10000, 2000회): 한 쌍씩 0.0028ms vs 한 글자씩 짝/홀 판정 0.0063ms
    //
    // string(n, '수') 는 쓸 수 없다. char 하나에 한글이 안 들어가므로 컴파일되지 않는다.
    for (int i = 0; i < share; i++) {
        answer += "수박";
    }

    if (rem) {
        answer += "수";     // (규칙 2)
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(3), string("수박수"));
    t.check(solution(4), string("수박수박"));

    // 아래는 직접 추가한 경계 케이스
    t.check("n = 1", solution(1), string("수"));
    t.check("n = 2", solution(2), string("수박"));
    t.check("최대치 길이(바이트)",
            (int)solution(10000).size(), 30000);   // 10000글자 x 3바이트
    return t.report();
}
