// https://school.programmers.co.kr/learn/courses/30/lessons/136798?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/25_기사단원의_무기.py

// Number of times solving questions: 1
// 2026-09-13

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

int solution(int number, int limit, int power) {
    // 규칙 1. i번 기사의 공격력 = i의 약수 개수.
    // 규칙 2. 공격력이 limit 을 넘으면 power 로 대체한다.
    // 규칙 3. number 최대 100,000. 각 수마다 1..i 를 전부 나눠보면 O(n^2) = 100억이라 불가능하다.

    int result = 0;

    for (int i = 1; i <= number; i++) {
        int count = 0;
        int d = 1;

        // i = d * (i/d) 이므로 약수는 항상 쌍으로 나온다.
        // 둘 중 작은 쪽은 반드시 sqrt(i) 이하이므로 거기까지만 훑으면 된다. O(n sqrt(n)). (규칙 3)
        while (d * d <= i) {
            if (i % d == 0) {
                if (d * d == i) {
                    count += 1;     // 완전제곱수의 제곱근은 짝이 자기 자신이라 한 번만 센다
                } else {
                    count += 2;     // d 와 i/d, 두 개
                }
            }

            d += 1;
        }

        // 센 자리에서 바로 더한다. 배열에 모아두면 10만 개 = 400KB 를 괜히 쓴다. (규칙 2)
        if (count > limit) {
            result += power;
        } else {
            result += count;
        }
    }

    return result;
}

// 참고: 더 빠른 방법이 있으나 이 문제에서는 불필요하다.
//   vector<int> cnt(number+1, 0);
//   for (int d = 1; d <= number; d++)
//       for (int m = d; m <= number; m += d) cnt[m]++;
//   "각 수의 약수를 찾는다"를 "각 수의 배수를 훑는다"로 뒤집으면
//   n/1 + n/2 + ... = O(n log n) 이 된다 (에라토스테네스의 체와 같은 발상).
//   실측(number=100,000): sqrt 방식 25.1ms vs 배수 순회 0.4ms. 60배.
//   그러나 25ms 로 이미 통과하므로 쓰지 않는다.
//   "이 최적화가 통과 여부를 바꾸는가" 가 아니면 거기서 멈춘다.

int main() {
    Tester t("solution");
    t.check(solution(5, 3, 2), 10);
    t.check(solution(10, 3, 2), 21);

    // 아래는 직접 추가한 경계 케이스
    t.check("기사 1명", solution(1, 2, 1), 1);
    t.check("limit 이 커서 대체 없음", solution(10, 100, 1), 27);
    t.check("limit 이 작아 대부분 대체", solution(10, 2, 1), 14);
    t.check("조금 큰 입력", solution(100, 5, 2), 273);
    return t.report();
}
