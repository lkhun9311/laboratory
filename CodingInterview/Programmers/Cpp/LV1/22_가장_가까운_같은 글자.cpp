// https://school.programmers.co.kr/learn/courses/30/lessons/142086?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!22_가장_가까운_같은 글자.py

// Number of times solving questions: 1
// 2026-09-02

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    // 규칙. 각 위치마다 "앞에 나온 같은 글자까지의 거리". 없으면 -1.
    //      뒤로 훑으면 최악 O(n^2) (10,000자에서 약 0.5초).
    //      각 글자가 마지막으로 나온 위치만 기억하면 한 번의 순회로 끝난다. O(n)
    // 주의. 존재 확인은 반드시 count 로. last_seen[letter] 로 읽으면 없는 키가 0으로 생성된다.
    vector<int> answer;
    unordered_map<char, int> last_seen;
    int s_size = s.size();

    for (int i=0; i<s_size; i++) {
        char letter = s[i];
        if (last_seen.count(letter)) {
            answer.push_back(i - last_seen[letter]);
        } else {
            answer.push_back(-1);
        }

        last_seen[letter] = i;   // 값을 구한 "뒤에" 갱신해야 자기 자신을 찾지 않는다
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("banana"), vector<int>{-1,-1,-1,2,2,2});
    t.check(solution("foobar"), vector<int>{-1,-1,1,-1,-1,-1});
    t.check("한 글자", solution("a"), vector<int>{-1});
    t.check("바로 옆", solution("aa"), vector<int>{-1,1});
    t.check("주기 3", solution("abcabc"), vector<int>{-1,-1,-1,3,3,3});
    return t.report();
}
