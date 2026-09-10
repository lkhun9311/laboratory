// https://school.programmers.co.kr/learn/courses/30/lessons/12919?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/78_서울에서_김서방_찾기.py

// Number of times solving questions: 1
// 2026-09-10

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>    // find. 스켈레톤에 없으므로 직접 추가한다
using namespace std;

string solution(vector<string> seoul) {
    // 규칙 1. seoul 에서 "Kim" 의 인덱스를 찾아 "김서방은 x에 있다" 를 반환한다.
    // 규칙 2. "Kim" 은 반드시 하나 존재하고 중복도 없다 → 못 찾은 경우를 방어할 필요가 없다.

    // find 는 값을 가리키는 "이터레이터"를 돌려준다. 인덱스가 아니다.
    auto it = find(seoul.begin(), seoul.end(), "Kim");

    // 시작 이터레이터와의 거리가 곧 인덱스다.
    // it - seoul.begin() 도 같지만, distance 는 의도가 이름에 드러나고
    // 뺄셈이 안 되는 이터레이터(list, set 등)에도 그대로 쓸 수 있다.
    //
    // 못 찾으면 find 는 seoul.end() 를 돌려주지만, 제한이 존재를 보장하므로 검사하지 않는다.
    // 도달할 수 없는 방어 코드는 오히려 버그의 자리가 된다. (규칙 2)
    int index = distance(seoul.begin(), it);

    // C++에는 문자열 포매팅이 없으므로 to_string 으로 바꿔 이어붙인다.
    return "김서방은 " + to_string(index) + "에 있다";
}

int main() {
    Tester t("solution");
    t.check(solution({"Jane", "Kim"}), string("김서방은 1에 있다"));

    // 아래는 직접 추가한 경계 케이스
    t.check("맨 앞", solution({"Kim", "Jane", "Tom"}), string("김서방은 0에 있다"));
    t.check("맨 뒤", solution({"a", "b", "Kim"}), string("김서방은 2에 있다"));
    t.check("혼자", solution({"Kim"}), string("김서방은 0에 있다"));
    t.check("두 자리 인덱스",
            solution({"a","b","c","d","e","f","g","h","i","j","Kim"}),
            string("김서방은 10에 있다"));
    return t.report();
}
