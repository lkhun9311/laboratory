// https://school.programmers.co.kr/learn/courses/30/lessons/12954?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/59_x만큼_간격이_있는_n개의_숫자.py

// Number of times solving questions: 1
// 2026-09-10

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

vector<long long> solution(int x, int n) {
    // 규칙 1. x 부터 시작해 x 씩 증가하는 숫자 n 개를 순서대로 담아 반환한다.
    // 규칙 2. |x| <= 10,000,000, n <= 1,000 이므로 최댓값이 100억이다.
    //         int 는 약 21억까지라 결과는 long long 이어야 한다.

    vector<long long> answer;

    // 정확히 n 개를 채우므로 reserve 가 확실한 이득이다.
    answer.reserve(n);

    for (int i = 0; i < n; i++) {
        // (long long) 캐스팅이 핵심이다.
        // x * (i+1) 로 쓰면 int * int 라 곱셈이 int 로 수행되고, 그 자리에서 이미 넘쳐 버린다.
        // long long 벡터에 담는 것은 "이미 망가진 값"을 담는 것이라 소용이 없다.
        // C++은 두 피연산자 타입이 다르면 큰 쪽으로 맞추므로, 한쪽만 long long 이면 된다.
        //
        // 실측(x=10,000,000, n=1,000): 캐스팅 없이는 1000개 중 786개(79%)가 오답.
        // i=214 에서 2,150,000,000 이 int 한계를 넘어 -2,144,967,296 으로 돌아버린다.
        // 주어진 예제(x=2, n=5)는 값이 작아 그대로 통과하므로 채점 전까지 드러나지 않는다. (규칙 2)
        answer.push_back((long long)x * (i + 1));
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(2, 5), vector<long long>{2, 4, 6, 8, 10});
    t.check(solution(4, 3), vector<long long>{4, 8, 12});
    t.check(solution(-4, 2), vector<long long>{-4, -8});

    // 아래는 직접 추가한 경계 케이스
    t.check("n = 1", solution(7, 1), vector<long long>{7});
    t.check("x = 0", solution(0, 3), vector<long long>{0, 0, 0});
    t.check("int 범위를 넘는 최댓값",
            vector<long long>{solution(10000000, 1000).back()},
            vector<long long>{10000000000LL});
    return t.report();
}
