// https://school.programmers.co.kr/learn/courses/30/lessons/76501?language=cpp
// 출처: 월간 코드 챌린지 시즌2
// 대응 Python 풀이: ../../Python/LV1/42_음양_더하기.py

// Number of times solving questions: 1
// 2026-09-10

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    // 규칙 1. absolutes[i] 의 부호는 signs[i] 가 정한다. true 면 양수, false 면 음수.
    // 규칙 2. 실제 정수들의 합을 반환한다.
    // 규칙 3. 길이·원소 모두 1000 이하 → 합의 최댓값이 1000 * 1000 = 100만.
    //         int(약 21억)로 충분하므로 long long 이 필요 없다. (59번과 반대 판단)

    int answer = 0;

    // size() 는 unsigned 라 int 와 직접 비교하면 -Wsign-compare 경고가 난다.
    int signs_size = signs.size();

    // 두 배열을 같은 인덱스로 짝지어 봐야 하므로 range-for 가 아니라 인덱스 루프를 쓴다.
    //
    // vector<bool> 은 다른 vector 와 달리 비트 단위로 압축 저장되는 특수화 타입이다.
    // 여기서는 읽기만 하므로 문제없지만, bool& 로 참조를 받으려 하면 컴파일되지 않는다.
    for (int i = 0; i < signs_size; i++) {
        if (signs[i]) {
            answer += absolutes[i];
        } else {
            answer -= absolutes[i];     // (규칙 1)
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({4, 7, 12}, {true, false, true}), 9);
    t.check(solution({1, 2, 3}, {false, false, true}), 0);

    // 아래는 직접 추가한 경계 케이스
    t.check("원소 하나", solution({5}, {false}), -5);
    t.check("전부 음수", solution({1, 2, 3}, {false, false, false}), -6);
    t.check("전부 양수", solution({1, 2, 3}, {true, true, true}), 6);
    return t.report();
}
