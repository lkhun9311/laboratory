// https://school.programmers.co.kr/learn/courses/30/lessons/42578?language=cpp
// 출처: 해시
// 대응 Python 풀이: ../../Python/LV2/!28_의상.py

// Number of times solving questions: 1
// 2026-09-19
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> clothesMap;
    for (const auto& cloth : clothes) {
        clothesMap[cloth[1]]++;
    }

    for (const auto& item : clothesMap) {
        int value = item.second;

        answer *= value+1;
    }

    answer--;;
    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}}), 5);
    t.check(solution({{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}), 3);

    // 아래는 직접 추가한 경계 케이스
    t.check("옷 하나", solution({{"only", "headgear"}}), 1);
    t.check("종류 두 개, 각 하나 — (1+1)*(1+1)-1", solution({{"a", "headgear"}, {"b", "eyewear"}}), 3);
    t.check("종류 세 개, 각 하나 — 2*2*2-1", solution({{"a", "x"}, {"b", "y"}, {"c", "z"}}), 7);
    return t.report();
}
