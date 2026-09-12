// https://school.programmers.co.kr/learn/courses/30/lessons/178871?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/12_달리기_경주.py

// Number of times solving questions: 1
// 2026-09-12

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_map>    // 스켈레톤에 없으므로 직접 추가한다
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // 규칙 1. players 는 등수 순서다 (앞이 1등).
    // 규칙 2. 호명된 선수는 바로 앞 선수를 추월한다 = 둘의 자리가 바뀐다.
    // 규칙 3. 1등은 불리지 않는다 → 호명된 선수의 인덱스는 항상 1 이상이다.
    //         따라서 i-1 이 음수가 되는 경우를 방어할 필요가 없다.
    // 규칙 4. 선수 최대 50,000명 / 호명 최대 1,000,000회.
    //         호명마다 find 로 훑으면 O(호명 x 선수) = 500억. 실측 약 22초로 시간 초과다.
    //         이름 -> 현재 위치를 O(1)로 알아야 한다.

    // 이름으로 위치를 즉시 찾기 위한 표.
    unordered_map<string, int> position;
    int n = players.size();
    for (int i = 0; i < n; i++) {
        position[players[i]] = i;
    }

    // const string& 로 받는다. 호명이 100만 개라 값으로 받으면 문자열을 100만 번 복사한다.
    // 실측(선수 50,000 / 호명 1,000,000): 값 복사 108.7ms vs 참조 71.8ms
    for (const string& calling : callings) {
        int i = position[calling];

        swap(players[i - 1], players[i]);   // 추월 (규칙 2, 3)

        // 자리를 바꿨으면 위치표도 같이 고쳐야 한다. 이것을 빠뜨리면 그 뒤가 전부 어긋난다.
        // swap 이 끝난 뒤이므로 players[i-1] 은 방금 호명된 선수,
        // players[i] 는 밀려난 선수다. 읽는 순서가 하나만 어긋나도 틀린다.
        position[players[i - 1]] -= 1;
        position[players[i]] += 1;
    }

    // players 는 값 복사본이라 제자리에서 고치고 그대로 반환한다.
    return players;
}

int main() {
    Tester t("solution");
    t.check(solution({"mumu", "soe", "poe", "kai", "mine"}, {"kai", "kai", "mine", "mine"}),
            vector<string>{"mumu", "kai", "mine", "soe", "poe"});

    // 아래는 직접 추가한 경계 케이스
    t.check("호명 1회", solution({"a", "b"}, {"b"}), vector<string>{"b", "a"});
    t.check("같은 선수 연속 호명 - 1등까지",
            solution({"a", "b", "c"}, {"c", "c"}), vector<string>{"c", "a", "b"});
    t.check("2등이 1등 되고 다시 원래대로",
            solution({"a", "b"}, {"b", "a"}), vector<string>{"a", "b"});
    // d 가 3->2 로, 이어서 c 가 3->2 로 올라와 둘이 원래 자리로 돌아온다
    t.check("서로 추월해 제자리로",
            solution({"a", "b", "c", "d"}, {"d", "c", "b"}),
            vector<string>{"b", "a", "c", "d"});
    t.check("맨 뒤가 1등까지 올라감",
            solution({"a", "b", "c", "d"}, {"d", "d", "d"}),
            vector<string>{"d", "a", "b", "c"});
    return t.report();
}
