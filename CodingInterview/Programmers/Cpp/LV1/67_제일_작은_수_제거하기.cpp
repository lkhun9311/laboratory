// https://school.programmers.co.kr/learn/courses/30/lessons/12935?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!67_제일_작은_수_제거하기.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> arr) {
    // 규칙 1. 가장 작은 수 하나를 뺀 배열. 원소가 서로 다르므로 지울 대상은 정확히 하나다.
    // 규칙 2. 빈 배열이 되면 대신 {-1} 을 돌려준다.

    // 1. 길이가 1이면 빼는 순간 비므로 먼저 걸러낸다. (규칙 2)
    int arr_size = arr.size();
    if (arr_size <= 1) {
        return {-1};
    }

    // 2. 최솟값을 찾는다. min_element 는 값이 아니라 위치 표식을 주므로 * 로 값을 꺼낸다.
    int min_value = *min_element(arr.begin(), arr.end());

    // 3. 최솟값만 빼고 순서대로 모은다. 인덱스가 필요 없으므로 원소를 직접 순회한다. (규칙 1)
    vector<int> answer;
    for (int value : arr) {
        if (value != min_value) {
            answer.push_back(value);
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({4,3,2,1}), vector<int>{4,3,2});
    t.check(solution({10}), vector<int>{-1});
    t.check("최솟값이 중간", solution({3,1,2}), vector<int>{3,2});
    t.check("최솟값이 처음", solution({1,2,3}), vector<int>{2,3});
    t.check("음수 포함", solution({5,-9,1,7}), vector<int>{5,1,7});
    return t.report();
}
