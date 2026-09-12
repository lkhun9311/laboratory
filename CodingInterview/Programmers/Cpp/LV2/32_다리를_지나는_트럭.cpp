// https://school.programmers.co.kr/learn/courses/30/lessons/42583?language=cpp
// 출처: 스택/큐
// 대응 Python 풀이: ../../Python/LV2/32_다리를_지나는_트럭.py

// Number of times solving questions: 1
// 2026-09-12

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 규칙 1. 트럭은 주어진 순서대로만 올라간다.
    // 규칙 2. 다리에 올라가서 내려오기까지 정확히 bridge_length 초가 걸린다.
    // 규칙 3. 다리 위 무게 합이 weight 를 넘으면 올라갈 수 없다.
    //         (다리 길이 = 최대 동시 통행 대수이기도 하다)
    // 규칙 4. 모든 트럭이 건너는 최소 시간을 반환한다.
    //
    // 1초 경과 (answer++)
    //         ↓
    // 다리 맨 앞 칸을 내린다 (0이면 빈 칸)
    // current_weight -= 내린 무게
    //         ↓
    // 대기 트럭이 남았나?
    //      ↙        ↘
    //    YES        NO
    //     ↓          ↓
    // 무게 여유 있나?  빈 칸(0) 밀어넣기
    //   ↙      ↘          ↓
    // YES      NO     (처음으로)
    //  ↓        ↓
    // 올린다  빈 칸(0)
    //  ↓        ↓
    //    (처음으로)
    //
    // 종료: 다리 위 무게 0 이고 대기 트럭도 없음
    //
    // 다리를 bridge_length 칸짜리 컨베이어 벨트로 본다.
    // 1초마다 전체가 한 칸씩 밀리고 맨 끝에서 하나가 떨어진다.
    // 빈 칸을 0 으로 채워두면 "다리 위 트럭 수"를 따로 셀 필요가 없다 —
    // 칸 수가 곧 bridge_length 로 고정되므로 규칙 3의 대수 제한이 저절로 지켜진다.
    int answer = 0;
    deque<int> bridge(bridge_length, 0);
    deque<int> truck(truck_weights.begin(), truck_weights.end());

    // 무게 합을 매번 다시 더하지 않고 들고 다닌다. 매초 다리를 훑으면 O(시간 x 다리길이) 가 된다.
    int current_weight = 0;

    // 다리 위가 비고 대기 트럭도 없으면 끝이다. (규칙 4)
    while (current_weight > 0 || truck.size() > 0) {
        answer++;

        // 맨 앞 칸이 다리를 벗어난다. 0 이면 빈 칸이라 아무 일도 일어나지 않는다. (규칙 2)
        int bridge_first = bridge.front();
        bridge.pop_front();
        current_weight -= bridge_first;

        int truck_size = truck.size();
        if (truck_size > 0) {
            int truck_weight = truck.front();

            // 방금 한 대가 내려간 뒤의 무게로 판정해야 한다. 순서가 바뀌면 올릴 수 있는데 못 올린다.
            if (current_weight + truck_weight <= weight) {
                truck.pop_front();
                bridge.push_back(truck_weight);
                current_weight += truck_weight;     // (규칙 1, 3)
            } else {
                bridge.push_back(0);                // 무게가 모자라 이번 초는 못 올린다
            }
        } else {
            bridge.push_back(0);                    // 대기 트럭이 없다 - 남은 트럭이 빠지기를 기다린다
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution(2, 10, {7, 4, 5, 6}), 8);
    t.check(solution(100, 100, {10}), 101);
    t.check(solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}), 110);

    // 아래는 직접 추가한 경계 케이스
    t.check("다리 길이 1", solution(1, 10, {5}), 2);
    t.check("전부 최대 무게라 한 대씩", solution(2, 10, {10, 10, 10}), 7);
    t.check("가벼워서 전부 동시에", solution(3, 100, {1, 1, 1}), 6);
    t.check("다리도 무게도 최소", solution(1, 1, {1}), 2);
    return t.report();
}
