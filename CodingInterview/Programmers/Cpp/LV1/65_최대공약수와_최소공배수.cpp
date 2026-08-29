// https://school.programmers.co.kr/learn/courses/30/lessons/12940?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!65_최대공약수와_최소공배수.py

// Number of times solving questions: 1
// 2026-08-29

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <numeric>
using namespace std;

vector<int> solution(int n, int m) {
    // 규칙. [최대공약수, 최소공배수] 를 돌려준다.
    //      gcd/lcm 은 C++17부터 <numeric> 에 있다.
    //      lcm = a*b/gcd 인데 a*b 를 먼저 하면 int 를 넘길 수 있으므로
    //      반드시 나눗셈을 먼저 해서 (n/gcd)*m 으로 쓴다.
    int gcd_result = gcd(n, m);

    return {gcd_result, (n/gcd_result)*m};
}

int main() {
    Tester t("solution");
    t.check(solution(3, 12), vector<int>{3, 12});
    t.check(solution(2, 5), vector<int>{1, 10});
    t.check("둘 다 1", solution(1, 1), vector<int>{1, 1});
    t.check("같은 수", solution(1000000, 1000000), vector<int>{1000000, 1000000});
    t.check("배수 관계", solution(4, 1000000), vector<int>{4, 1000000});
    t.check("서로소 (int 범위 안)", solution(1000, 999), vector<int>{1, 999000});
    return t.report();
}
