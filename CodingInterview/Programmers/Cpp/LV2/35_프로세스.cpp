// https://school.programmers.co.kr/learn/courses/30/lessons/42587?language=cpp
// 출처: 스택/큐
// 대응 Python 풀이: ../../Python/LV2/35_프로세스.py

// Number of times solving questions: 1
// 2026-09-12

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <deque>        // deque. 앞에서 빼고 뒤에 넣는 것이 둘 다 O(1)
#include <algorithm>    // max
using namespace std;

int solution(vector<int> priorities, int location) {
    // 규칙 1. 대기 큐 맨 앞을 꺼내, 큐 안에 더 높은 우선순위가 있으면 맨 뒤로 보낸다.
    // 규칙 2. 없으면 실행한다.
    // 규칙 3. location 번째(0-based)에 있던 프로세스가 몇 번째로 실행되는지(1-based) 반환한다.
    //
    //  맨 앞 프로세스를 본다   ← 큐가 빌 일은 없다 (찾는 프로세스는 반드시 실행된다)
    //          ↓
    //  더 높은 우선순위가 있나?
    //       ↙        ↘
    //     YES        NO
    //      ↓          ↓
    //  맨 뒤로 이동   실행 (pop)
    //      ↓          ↓
    //  (처음으로)  실행 횟수 +1
    //                 ↓
    //         내가 찾던 프로세스?
    //            ↙        ↘
    //          YES        NO
    //           ↓          ↓
    //      실행 횟수 반환  (처음으로)

    int executed = 0;

    // 맨 뒤로 보낸 것을 나중에 다시 꺼내야 하므로 큐가 진짜로 필요하다.
    // (34번 기능개발은 한 번 지나간 작업을 다시 볼 일이 없어 큐가 불필요했다 - 대비해서 기억할 것)
    //
    // 우선순위만 담으면 안 된다. [1,1,9,1,1,1] 처럼 같은 값이 여럿이면
    // 어느 것이 location 번째였는지 구분할 수 없기 때문이다.
    // 원래 인덱스를 함께 들고 다녀야 "이게 내가 찾던 그 프로세스"임을 알 수 있다. (규칙 3)
    deque<pair<int, int>> waiting;      // (우선순위, 원래 인덱스)

    int n = priorities.size();
    for (int i = 0; i < n; i++) {
        waiting.push_back({priorities[i], i});
    }

    while (true) {
        pair<int, int> current = waiting.front();

        // 남아 있는 것들 중 최댓값을 구한다.
        // 임시 vector 를 만들어 max_element 를 부를 필요 없이 덱을 직접 훑으면 된다.
        // const auto& 로 받으면 원소 복사도 없다.
        int max_priority = 0;
        for (const auto& p : waiting) {
            max_priority = max(max_priority, p.first);
        }

        waiting.pop_front();

        if (current.first < max_priority) {
            waiting.push_back(current);     // 더 급한 것이 있으니 맨 뒤로. (규칙 1)
            continue;
        }

        // 여기 왔다는 것은 현재가 최고 우선순위라는 뜻이다. 실행한다. (규칙 2)
        executed++;

        if (current.second == location) {
            return executed;                // 찾던 프로세스였다. (규칙 3)
        }
    }
}

int main() {
    Tester t("solution");
    t.check(solution({2, 1, 3, 2}, 2), 1);
    t.check(solution({1, 1, 9, 1, 1, 1}, 0), 5);

    // 아래는 직접 추가한 경계 케이스
    t.check("프로세스 1개", solution({5}, 0), 1);
    t.check("전부 같은 우선순위, 마지막", solution({3, 3, 3, 3}, 3), 4);
    t.check("내가 최고 우선순위인데 맨 뒤", solution({1, 1, 9}, 2), 1);
    t.check("같은 값이 여럿, 앞의 것", solution({2, 2, 2}, 0), 1);
    return t.report();
}
