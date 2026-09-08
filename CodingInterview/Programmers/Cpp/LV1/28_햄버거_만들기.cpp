// https://school.programmers.co.kr/learn/courses/30/lessons/133502?language=cpp
// 출처: 연습문제 (2022 KAKAO TECH INTERNSHIP)
// 대응 Python 풀이: ../../Python/LV1/28_햄버거_만들기.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    // 규칙 1. 아래에서 위로 쌓인 재료가 연속으로 1,2,3,1(빵-야채-고기-빵)이면 햄버거 하나로 빼낸다.
    // 규칙 2. 빼내면 그 위아래가 맞붙어 또 햄버거가 될 수 있다.
    // 규칙 3. 길이가 최대 1,000,000이라 매번 전체를 다시 훑는 O(n^2)은 통과할 수 없다.

    int answer = 0;

    // 새 재료를 하나 얹었을 때 새로 완성될 수 있는 햄버거는 "맨 위 4개"뿐이다.
    // 그 아래는 하나도 변하지 않았으니 다시 볼 이유가 없다 — 이것이 O(n)으로 내려가는 지점이다. (규칙 3)
    //
    // 스택을 따로 만들지 않고 매개변수 ingredient 를 그대로 스택으로 쓴다.
    // ingredient 는 이미 호출자 값의 복사본이므로 마음대로 고쳐도 된다.
    // top 은 스택의 크기이자 "다음에 쓸 자리"다.
    int top = 0;

    for (int x : ingredient) {
        // 쌓기 = 자리에 값을 쓰고 top 을 1 늘린다.
        //
        // 같은 배열을 읽으면서 쓰지만 겹치지 않는다.
        // top 은 한 번에 1씩만 늘고 가끔 4씩 줄므로 "쓰는 자리(top) <= 읽는 자리"가 항상 성립한다.
        // 최악이어도 방금 읽은 자기 자리에 쓰는 것뿐이고, 그 값은 이미 x 에 복사돼 있다.
        ingredient[top++] = x;

        // 찾는 패턴이 아래에서 위로 1,2,3,1 이므로 인덱스도 top-4 -> top-1 순서로 적는다.
        // 값(1,2,3,1)과 인덱스가 나란히 늘어나 빠뜨린 자리가 눈에 보인다.
        if (top >= 4 && ingredient[top-4] == 1 && ingredient[top-3] == 2 && ingredient[top-2] == 3 && ingredient[top-1] == 1) {
            // 빼내기 = 값을 지우는 것이 아니라 "여기까지만 유효"라고 정하는 것.
            // top 이 줄면 그 아래가 새 맨 위가 되고, 다음 재료를 쌓을 때 자동으로 다시 검사된다.
            // 따라서 "빼면 위아래가 맞붙는다"를 위한 별도 처리가 필요 없다. (규칙 2)
            top -= 4;
            answer++;
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({2, 1, 1, 2, 3, 1, 2, 3, 1}), 2);
    t.check(solution({1, 3, 2, 1, 2, 1, 3, 1, 2}), 0);

    // 아래는 직접 추가한 경계 케이스
    t.check("딱 한 개", solution({1, 2, 3, 1}), 1);
    t.check("4개 미만", solution({1, 2, 3}), 0);
    t.check("빼내니 맞붙어 또 완성", solution({1, 2, 1, 2, 3, 1, 3, 1}), 2);
    t.check("순서만 뒤집힘", solution({1, 3, 2, 1}), 0);
    return t.report();
}
