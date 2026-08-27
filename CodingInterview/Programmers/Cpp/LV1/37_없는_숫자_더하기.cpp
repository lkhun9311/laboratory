// https://school.programmers.co.kr/learn/courses/30/lessons/86051?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!37_없는_숫자_더하기.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
using namespace std;

int solution(vector<int> numbers) {
    // 규칙. 0~9 중 numbers에 없는 숫자들의 합.
    //      "없는 것들의 합 = 전부의 합 - 있는 것들의 합" 이므로 집합 연산이 필요 없다.
    //      numbers의 원소가 서로 다르다는 제한이 중복 걱정을 없애준다.
    const int SUM_OF_0_TO_9 = 45;   // 0+1+2+...+9

    return SUM_OF_0_TO_9 - accumulate(numbers.begin(), numbers.end(), 0);
}

int main() {
    Tester t("solution");
    t.check(solution({1,2,3,4,6,7,8,0}), 14);
    t.check(solution({5,8,4,0,6,7,9}), 6);
    t.check("하나만 있음", solution({0}), 45);
    t.check("아홉 개 있음", solution({0,1,2,3,4,5,6,7,8}), 9);
    return t.report();
}
