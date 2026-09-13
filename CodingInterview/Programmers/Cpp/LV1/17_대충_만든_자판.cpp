// https://school.programmers.co.kr/learn/courses/30/lessons/160586?language=cpp
// 출처: 2022 KAKAO TECH INTERNSHIP
// 대응 Python 풀이: ../../Python/LV1/17_대충_만든_자판.py

// Number of times solving questions: 1
// 2026-09-13

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>    // 스켈레톤에 없으므로 직접 추가한다
#include <algorithm>        // min. unordered_map 이 간접으로 끌어와 우연히 컴파일될 수 있으나
                            // 컴파일러·표준 라이브러리 버전에 따라 터진다. 명시한다.
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    // 규칙 1. keymap[i] 의 j번째 문자는 그 키를 j+1 번 눌러야 나온다.
    // 규칙 2. 같은 문자가 여러 키에 있으면 가장 적게 누르는 쪽을 쓴다.
    // 규칙 3. targets 의 문자 중 하나라도 어느 키에도 없으면 그 문자열은 -1.

    vector<int> answer;

    // 문자 -> 그 문자를 누르는 최소 횟수. 미리 만들어 두면 target 을 볼 때 한 번에 찾을 수 있다.
    // 이걸 안 만들면 문자마다 keymap 전체를 다시 훑어야 한다.
    unordered_map<char, int> keymap_dict;

    for (const auto& keys : keymap) {
        int n = keys.size();
        for (int i = 0; i < n; i++) {
            // 처음 보는 문자면 그대로, 이미 있으면 더 작은 쪽을 남긴다. (규칙 2)
            if (keymap_dict.find(keys[i]) == keymap_dict.end()) {
                keymap_dict[keys[i]] = i + 1;
            } else {
                keymap_dict[keys[i]] = min(i + 1, keymap_dict[keys[i]]);
            }
        }
    }

    for (const auto& target : targets) {
        int tmp_result = 0;
        int n = target.size();

        for (int i = 0; i < n; i++) {
            char t = target[i];

            // 없는 문자를 만나면 나머지를 볼 필요가 없다. (규칙 3)
            // find 로 확인한다 - keymap_dict[t] 를 바로 쓰면 없는 키가 0 으로 생겨버린다.
            if (keymap_dict.find(t) == keymap_dict.end()) {
                tmp_result = -1;
                break;
            } else {
                tmp_result += keymap_dict[t];
            }
        }

        answer.push_back(tmp_result);
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({"ABACD", "BCEFD"}, {"ABCD", "AABB"}), vector<int>{9, 4});
    t.check(solution({"AA"}, {"B"}), vector<int>{-1});
    t.check(solution({"AGZ", "BSSS"}, {"ASA", "BGZ"}), vector<int>{4, 6});

    // 아래는 직접 추가한 경계 케이스
    t.check("일부만 불가능", solution({"ABC"}, {"AB", "AX", "C"}), vector<int>{3, -1, 3});
    t.check("같은 문자가 여러 키에 - 더 앞쪽을 쓴다",
            solution({"ZZA", "A"}, {"A"}), vector<int>{1});
    return t.report();
}
