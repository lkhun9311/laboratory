// https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=cpp
// 출처: 완전탐색
// 대응 Python 풀이: ../../Python/LV1/!51_모의고사.py

// Number of times solving questions: 1
// 2026-09-16
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> student1 = {1,2,3,4,5};
    vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int answer1 = 0;
    int answer2 = 0;
    int answer3 = 0;
    int n = answers.size();

    for (int i=0; i<n; i++) {
        if (answers[i] == student1[i%student1.size()]) {
            answer1++;
        }

        if (answers[i] == student2[i%student2.size()]) {
            answer2++;
        }

        if (answers[i] == student3[i%student3.size()]) {
            answer3++;
        }
    }

    int maxScore = max(answer1, max(answer2, answer3));

    if (maxScore == answer1) {
        answer.push_back(1);
    }

    if (maxScore == answer2) {
        answer.push_back(2);
    }

    if (maxScore == answer3) {
        answer.push_back(3);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1, 2, 3, 4, 5}), vector<int>{1});
    t.check(solution({1, 3, 2, 4, 2}), vector<int>{1, 2, 3});

    // 아래는 직접 추가한 경계 케이스
    t.check("문제 하나, 1번만 맞음", solution({1}), vector<int>{1});
    t.check("문제 하나, 2번만 맞음", solution({2}), vector<int>{2});
    t.check("문제 하나, 셋 다 0점", solution({5}), vector<int>{1, 2, 3});
    t.check("3번 패턴이 한 바퀴", solution({3, 3, 1, 1, 2, 2, 4, 4, 5, 5}), vector<int>{3});
    return t.report();
}
