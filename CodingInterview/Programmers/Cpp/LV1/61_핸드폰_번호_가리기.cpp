// https://school.programmers.co.kr/learn/courses/30/lessons/12948?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!61_핸드폰_번호_가리기.py

// Number of times solving questions: 1
// 2026-08-27

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

string solution(string phone_number) {
    // 규칙. 뒤 4자리만 남기고 앞은 전부 *로 가린다. 길이가 4 이상이라 가릴 개수는 0 이상이다.
    //      C++에는 음수 인덱스가 없으므로 "뒤 4자리"의 시작 칸을 직접 계산한다.
    int phone_number_size = phone_number.size();

    // string(개수, 글자) 는 그 글자를 개수만큼 이어 붙인다. 파이썬 "*" * n 에 대응.
    string tmp_phone_number = string(phone_number_size - 4, '*');

    // substr(시작) 은 개수를 생략하면 끝까지. 가린 개수와 시작 칸이 같아야 앞뒤가 맞는다.
    string last_4_of_phone_number = phone_number.substr(phone_number_size - 4);

    return tmp_phone_number + last_4_of_phone_number;
}

int main() {
    Tester t("solution");
    t.check(solution("01033334444"), "*******4444");
    t.check(solution("027778888"), "*****8888");
    t.check("최소 길이 4", solution("4444"), "4444");
    t.check("길이 5", solution("54321"), "*4321");
    t.check("최대 길이 20", solution("12345678901234567890"), "****************7890");
    return t.report();
}
