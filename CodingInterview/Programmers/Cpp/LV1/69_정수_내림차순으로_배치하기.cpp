// https://school.programmers.co.kr/learn/courses/30/lessons/12933?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!69_정수_내림차순으로_배치하기.py

// Number of times solving questions: 1
// 2026-08-29

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

long long solution(long long n) {
    // 규칙. n의 각 자릿수를 큰 것부터 정렬해 하나의 정수로 되돌린다.
    //      string 자체가 글자의 나열이라 쪼개고 합치는 단계 없이 그대로 정렬할 수 있다.
    //      n이 80억까지 가므로 stoi(21억)가 아니라 stoll을 쓴다.
    string s = to_string(n);

    sort(s.begin(), s.end(), greater<char>());

    return stoll(s);
}

int main() {
    Tester t("solution");
    t.check(solution(118372), 873211LL);
    t.check("한 자리", solution(1), 1LL);
    t.check("0이 뒤로", solution(10), 10LL);
    t.check("0이 여럿", solution(1000), 1000LL);
    t.check("최댓값 80억", solution(8000000000LL), 8000000000LL);
    t.check("전부 다름", solution(123456789), 987654321LL);
    return t.report();
}
