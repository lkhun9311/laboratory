// https://school.programmers.co.kr/learn/courses/30/lessons/42584?language=cpp
// 출처: 스택/큐
// 대응 Python 풀이: ../../Python/LV2/!33_주식가격.py

// Number of times solving questions: 1
// 2026-09-20
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int n = prices.size();

    for (int i=0; i<n; i++) {
        int count = 0;

        for (int j=i+1; j<n; j++) {
            count ++;

            if (prices[i] > prices[j]) {
                break;
            }
        }

        answer.push_back(count);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1, 2, 3, 2, 3}), vector<int>{4, 3, 1, 1, 0});

    // 아래는 직접 추가한 경계 케이스 (prices 길이 2~100,000, 값 1~10,000)
    t.check("가장 짧은 입력, 떨어지지 않음", solution({1, 2}), vector<int>{1, 0});
    t.check("가장 짧은 입력, 떨어짐", solution({2, 1}), vector<int>{1, 0});
    t.check("계속 떨어진다", solution({5, 4, 3, 2, 1}), vector<int>{1, 1, 1, 1, 0});
    t.check("전부 같은 값 — 떨어진 적이 없다", solution({3, 3, 3, 3}), vector<int>{3, 2, 1, 0});
    t.check("계속 오른다", solution({1, 2, 3, 4, 5}), vector<int>{4, 3, 2, 1, 0});
    t.check("떨어졌다가 다시 오른다", solution({4, 1, 5, 2, 3}), vector<int>{1, 3, 1, 1, 0});
    return t.report();
}
