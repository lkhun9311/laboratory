// https://school.programmers.co.kr/learn/courses/30/lessons/42626?language=cpp
// 출처: 힙(Heap)
// 대응 Python 풀이: ../../Python/LV2/43_더_맵게.py

// Number of times solving questions: 1
// 2026-09-12

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <queue>        // priority_queue
#include <functional>   // greater
using namespace std;

int solution(vector<int> scoville, int K) {
    // 규칙 1. 모든 음식이 K 이상이 될 때까지, 가장 안 매운 둘을 섞는다.
    //         새 음식 = 가장 안 매운 것 + 두 번째로 안 매운 것 * 2
    // 규칙 2. 섞은 횟수를 반환한다. 전부 K 이상으로 만들 수 없으면 -1.
    // 규칙 3. 원소 최대 1,000,000개 → 매번 정렬하거나 훑으면 통과할 수 없다. O(n log n) 이어야 한다.
    //
    // 가장 작은 음식 >= K ?
    //      ↙        ↘
    //    YES        NO
    //     ↓          ↓
    //  answer    음식이 2개 미만인가?
    //  return         ↙        ↘
    //               YES        NO
    //                ↓          ↓
    //               -1    가장 작은 음식 2개 꺼냄
    //                           ↓
    //                  new = first + second * 2
    //                           ↓
    //                     new 를 다시 넣음
    //                           ↓
    //                       answer++
    //                           ↓
    //                      (처음으로)

    int answer = 0;

    // 매번 "가장 작은 둘"을 꺼내고 섞은 결과를 다시 넣어야 한다.
    // 그 새 값이 다음 라운드의 최솟값일 수도 있으므로 다시 꺼내 볼 일이 있다 → 힙이 맞다. (규칙 3)
    //
    // C++ priority_queue 는 기본이 "최대 힙"이다. Python heapq 가 기본 최소 힙인 것과 정반대다.
    // 최소 힙을 쓰려면 greater<T> 를 세 번째 인자로 넘겨야 하고,
    // 그러려면 두 번째 인자(컨테이너 타입)도 함께 적어야 한다.
    //
    // 타입이 long long 인 이유:
    //   섞기는 가장 작은 값이 K 미만인 동안 계속되고 K 는 최대 10억이다.
    //   new = first + second*2 는 30억까지 갈 수 있는데 int 한계는 21억이다.
    //   실측: 1,000,000 짜리 원소 128개 + K=10억 에서 int 로 계산하면 -1 이 나온다 (정답 127).
    //   값은 섞을 때마다 약 3배씩 자라 1e6 * 3^7 ≈ 21.9억 에서 이미 넘는다.
    //   주어진 예제와 작은 입력은 전부 통과하므로 채점 전까지 드러나지 않는다.
    //
    // 범위 생성자로 한 번에 만든다. 하나씩 push 하는 것보다 빠르고 Python 의 heapify 에 대응한다.
    priority_queue<long long, vector<long long>, greater<long long>> pq(scoville.begin(), scoville.end());

    while (pq.top() < K) {
        // 섞을 때마다 둘이 나가고 하나가 들어와 크기가 1씩 준다.
        // 재료가 하나뿐이면 더 섞을 수 없다 = 만들 수 없다. (규칙 2)
        // 힙이 완전히 비는 경우는 없다.
        if (pq.size() < 2) {
            return -1;
        }

        // auto 는 참조와 const 를 떼고 값 타입(long long)으로 추론한다.
        // 힙 타입을 바꿔도 변수가 따라오므로, "힙만 long long 으로 바꾸고 변수는 int" 사고를 막아준다.
        // 단 auto& 로 받으면 안 된다 — 힙 내부를 가리키는 참조라 pop() 뒤에는 죽은 자리를 읽는다.
        auto first_s = pq.top();
        pq.pop();

        auto second_s = pq.top();
        pq.pop();

        pq.push(first_s + second_s * 2);    // (규칙 1)
        answer++;
    }

    // answer 는 최대 100만 회라 int 로 충분하다.
    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1, 2, 3, 9, 10, 12}, 7), 2);

    // 아래는 직접 추가한 경계 케이스
    t.check("이미 전부 K 이상", solution({10, 20}, 5), 0);
    t.check("섞어도 불가능", solution({1, 1}, 100), -1);
    t.check("원소 2개, 한 번에 성공", solution({1, 2}, 5), 1);
    t.check("K = 0", solution({0, 0, 0}, 0), 0);
    // int 로 계산하면 오버플로로 -1 이 나오는 입력 (1,000,000 짜리 128개, K = 10억)
    t.check("오버플로 유발", solution(vector<int>(128, 1000000), 1000000000), 127);
    return t.report();
}
