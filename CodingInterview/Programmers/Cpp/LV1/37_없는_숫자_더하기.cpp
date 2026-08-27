// https://school.programmers.co.kr/learn/courses/30/lessons/86051?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!37_없는_숫자_더하기.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
#include <string>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;

int solution(vector<int> numbers) {
    // 규칙. 0~9 중 numbers에 없는 숫자들의 합.
    //      numbers의 원소는 서로 다르므로 개수를 셀 필요가 없다 -> 집합으로 충분하다.

    // 1. 주어진 것과 0~9 전부를 각각 집합으로 만든다.
    //    C++에는 range()가 없으므로 0~9는 직접 채운다.
    set<int> given_digits(numbers.begin(), numbers.end());
    set<int> all_digits;
    for (int i = 0; i <= 9; i++) all_digits.insert(i);

    // 2. 차집합 = 없는 것들. C++에는 집합 뺄셈 연산자가 없어 set_difference를 쓴다.
    //    결과를 받을 그릇을 미리 만들고 back_inserter로 채워 넣는다.
    //    set_difference는 양쪽이 정렬돼 있어야 하므로 unordered_set이 아니라 set이다.
    vector<int> missing_digits;
    set_difference(all_digits.begin(), all_digits.end(),
                   given_digits.begin(), given_digits.end(),
                   back_inserter(missing_digits));

    // 3. 없는 것들의 합.
    return accumulate(missing_digits.begin(), missing_digits.end(), 0);
}

int main() {
    Tester t("solution");
    t.check(solution({1,2,3,4,6,7,8,0}), 14);
    t.check(solution({5,8,4,0,6,7,9}), 6);
    t.check("하나만 있음", solution({0}), 45);
    t.check("아홉 개 있음", solution({0,1,2,3,4,5,6,7,8}), 9);
    return t.report();
}
