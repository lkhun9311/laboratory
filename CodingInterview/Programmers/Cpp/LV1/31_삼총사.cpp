// https://school.programmers.co.kr/learn/courses/30/lessons/131705?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/!31_삼총사.py

// Number of times solving questions: 1
// 2026-09-02

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> number) {
    // 규칙. 세 학생의 번호 합이 0이면 삼총사. 그런 조합의 개수를 센다.
    //      길이가 최대 13이라 13C3 = 286가지뿐이므로 전부 확인해도 된다. (완전탐색)
    //      j 를 i+1 부터, k 를 j+1 부터 돌려 i < j < k 를 강제하면
    //      (0,1,2) 와 (2,1,0) 같은 같은 조합이 중복으로 세어지지 않는다.
    int answer = 0;
    int number_size = number.size();

    for (int i=0; i<number_size; i++) {
        for (int j=i+1; j<number_size; j++) {
            for (int k=j+1; k<number_size; k++) {
                if (number[i]+number[j]+number[k] == 0) {
                    answer += 1;
                }
            }
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({-2, 3, 0, 2, -5}), 2);
    t.check(solution({-3, -2, -1, 0, 1, 2, 3}), 5);
    t.check("최소 길이 3, 성립", solution({1, -1, 0}), 1);
    t.check("최소 길이 3, 불성립", solution({1, 1, 1}), 0);
    t.check("같은 번호 여럿", solution({0, 0, 0, 0}), 4);
    t.check("최대 길이 13 전부 0", solution(vector<int>(13, 0)), 286);
    return t.report();
}
