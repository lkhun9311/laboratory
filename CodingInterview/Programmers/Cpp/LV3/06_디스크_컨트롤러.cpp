// https://school.programmers.co.kr/learn/courses/30/lessons/42627?language=cpp
// 출처: 힙(Heap)
// 대응 Python 풀이: ../../Python/LV3/!06_디스크_컨트롤러.py

// Number of times solving questions: 1
// 2026-09-19
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int jobs_size = jobs.size();
    vector<tuple<int, int, int>> sorted_jobs;

    // 요청 시각 순으로 정렬
    for (int i=0; i<jobs_size; i++) {
        sorted_jobs.push_back({
            jobs[i][0],
            jobs[i][1],
            i
        });
    }
    sort(sorted_jobs.begin(), sorted_jobs.end());

    // 대기 큐 prioirty_queue
    // 최소 힙
    // 소요 시간, 요청 시각, 작업 번호 순으로 저장
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    int index = 0;
    int current = 0;
    int total = 0;

    while (
        index<jobs_size ||
        !pq.empty()
    ) {
        if (
            pq.empty() &&
            index < jobs_size &&
            current < get<0>(sorted_jobs[index])
        ) {
            current = get<0>(sorted_jobs[index]);
        }

        while (
            index < jobs_size &&
            get<0>(sorted_jobs[index]) <= current
        ) {
            int consumed_time = get<1>(sorted_jobs[index]);
            int requested_time = get<0>(sorted_jobs[index]);
            int job_no = get<2>(sorted_jobs[index]);

            pq.push({consumed_time, requested_time, job_no});
            index++;
        }

        auto job = pq.top();
        pq.pop();

        int consumed_time = get<0>(job);
        int requested_time = get<1>(job);

        current += consumed_time;
        total += current - requested_time;
    }


    return total/jobs_size;
}

int main() {
    Tester t("solution");
    t.check(solution({{0, 3}, {1, 9}, {2, 6}}), 9);

    // 아래는 직접 추가한 경계 케이스
    t.check("작업 하나", solution({{0, 5}}), 5);
    t.check("요청이 겹치지 않아 기다릴 일이 없다", solution({{0, 1}, {10, 1}}), 1);
    t.check("0 시각에 몰려 있고 짧은 것부터 (1+3+6)/3", solution({{0, 1}, {0, 2}, {0, 3}}), 3);
    t.check("디스크가 쉬는 구간이 있다", solution({{0, 2}, {5, 3}}), 2);
    t.check("같은 소요 시간", solution({{0, 2}, {1, 2}}), 2);
    return t.report();
}
