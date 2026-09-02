// https://school.programmers.co.kr/learn/courses/30/lessons/134240?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!27_푸드_파이트_대회.py

// Number of times solving questions: 1
// 2026-09-02

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    // 규칙 1. 두 선수가 똑같이 나눠 먹으므로 각 음식은 food[i] / 2 개씩. 홀수면 하나 남긴다.
    // 규칙 2. food[0] 은 물이고 가운데에 하나만 놓이므로 반복은 1번부터.
    // 규칙 3. 오른쪽은 왼쪽을 뒤집은 것 — 두 선수의 순서가 같아야 하므로.
    string left = "";

    // size() 는 부호 없는 타입이라 int 와 직접 비교하면 경고가 난다.
    int food_size = food.size();
    for (int number=1; number<food_size; number++) {
        int portion = food[number] / 2;
        // C++ 에는 문자열 반복(str * n)이 없다. string(개수, 글자) 생성자를 쓴다.
        // '0' + number 는 숫자를 문자로 바꾸는 관용구 ('0'+2 == '2').
        left += string(portion, '0' + number);
    }

    // reverse 는 제자리 뒤집기이고 반환값이 void 다.
    // 원본을 남겨야 하므로 먼저 복사한 뒤 그 복사본을 뒤집는다.
    string right = left;
    reverse(right.begin(), right.end());

    return left + "0" + right;
}

int main() {
    Tester t("solution");
    t.check(solution({1,3,4,6}), "1223330333221");
    t.check(solution({1,7,1,2}), "111303111");
    t.check("최소 길이 2", solution({1,2}), "101");
    t.check("앞 음식이 0개", solution({1,1,2}), "202");
    t.check("홀수 나눗셈", solution({1,5,5}), "112202211");
    t.check("최대 길이 9", solution({1,1,1,1,1,1,1,1,9}), "888808888");
    return t.report();
}
