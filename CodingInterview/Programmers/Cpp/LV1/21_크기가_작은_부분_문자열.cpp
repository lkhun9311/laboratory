// https://school.programmers.co.kr/learn/courses/30/lessons/147355?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!21_크기가_작은_부분_문자열.py

// Number of times solving questions: 1
// 2026-08-30

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    // 규칙. t 에서 p 와 길이가 같은 부분문자열 중, p 이하인 것의 개수.
    //      p 의 길이가 최대 18자리라 int(10자리)로는 담을 수 없다.
    //      stoi 는 out_of_range 예외를 던지므로 반드시 stoll 을 쓴다.
    //      p 는 반복 내내 바뀌지 않으므로 변환은 반복문 밖에서 한 번만.
    int answer = 0;
    int t_size = t.size();
    int p_size = p.size();
    long long p_number = stoll(p);

    // 시작 위치는 0 부터 t_size - p_size 까지. 그 뒤로는 p_size 만큼 못 채운다.
    for (int i=0; i<=(t_size-p_size); i++) {
        long long number = stoll(t.substr(i, p_size));   // substr(시작, 개수)
        if (number <= p_number) {
            answer += 1;
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("3141592", "271"), 2);
    t.check(solution("500220839878", "7"), 8);
    t.check(solution("10203", "15"), 3);
    t.check("0으로 시작", solution("0000", "0"), 4);
    t.check("18자리 최대", solution("999999999999999999", "999999999999999999"), 1);
    t.check("t와 p가 같음", solution("123", "123"), 1);
    return t.report();
}
