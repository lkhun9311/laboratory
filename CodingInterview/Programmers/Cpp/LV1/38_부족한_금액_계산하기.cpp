// https://school.programmers.co.kr/learn/courses/30/lessons/82612?language=cpp
// 출처: 연습문제 (weekly challenge)
// 대응 Python 풀이: ../../Python/LV1/38_부족한_금액_계산하기.py

// Number of times solving questions: 1
// 2026-09-12

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

long long solution(int price, int money, int count)
{
    // 규칙 1. c 번째 탑승 비용은 price * c 원이다 (c = 1 .. count).
    // 규칙 2. 총비용이 money 보다 많으면 모자란 금액을, 아니면 0 을 반환한다.
    // 규칙 3. price 2,500 / count 2,500 이면 총비용이 78억이라 int(21억)를 넘는다.

    // 누적 변수만 long long 이면 된다.
    // 한 항 price*c 는 최대 2500*2500 = 6,250,000 이라 int 안에서 안전하고,
    // 커지는 것은 누적값뿐이기 때문이다.
    //
    // 공식 price * count * (count+1) / 2 를 int 로 쓰면 곱하는 순간 78억이 되어
    // 그 자리에서 넘친다 (실측: 최대치에서 0 이 나온다).
    // 루프는 최대 2,500번이라 성능도 문제없다 — 공식이 항상 나은 것은 아니다. (규칙 3)
    long long remain = money;

    for (int c = 1; c < count + 1; c++) {
        remain -= price * c;        // (규칙 1)
    }

    if (remain >= 0) {
        return 0;                   // 돈이 충분하다 (규칙 2)
    }

    return (-1) * remain;           // 모자란 금액은 양수로 돌려준다
}

int main() {
    Tester t("solution");
    t.check(solution(3, 20, 4), 10LL);

    // 아래는 직접 추가한 경계 케이스
    t.check("돈이 충분", solution(1, 100, 5), 0LL);
    t.check("정확히 딱 맞음", solution(3, 30, 4), 0LL);
    t.check("한 번만 탑승", solution(5, 1, 1), 4LL);
    t.check("최대치 - int 로 계산하면 넘침", solution(2500, 1, 2500), 7815624999LL);
    return t.report();
}
