// https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
// 출처: 연습문제 (월간 코드 챌린지 시즌1)
// 대응 Python 풀이: ../../Python/LV1/46_두_개_뽑아서_더하기.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <set>          // 스켈레톤에 없다. 직접 추가해야 한다.
using namespace std;

vector<int> solution(vector<int> numbers) {
    // 규칙 1. 서로 다른 두 "인덱스"의 수를 뽑아 더한다. 같은 자리를 두 번 뽑을 수 없다.
    //         (값이 같아도 인덱스가 다르면 서로 다른 쌍이다 — [1, 1]도 유효한 쌍)
    // 규칙 2. 만들 수 있는 합을 중복 없이, 오름차순으로 담아 반환한다.

    // set은 중복 제거와 정렬을 동시에 해준다. 넣는 순간 오름차순 상태로 유지되므로
    // 나중에 sort를 따로 부를 필요가 없다. (규칙 2)
    // Python의 set과 이름은 같지만 성질이 다르다 — Python set은 순서가 없다.
    set<int> tmp_result;

    int numbers_size = numbers.size();

    // j를 i+1부터 시작해 (i, j)와 (j, i)를 한 번만 세고, i == j 인 "같은 자리 두 번"도 배제한다. (규칙 1)
    for (int i=0; i<numbers_size; i++) {
        for (int j=i+1; j<numbers_size; j++) {
            tmp_result.insert(numbers[i] + numbers[j]);
        }
    }

    // set을 순회하면 이미 오름차순이므로, 범위로 옮기기만 하면 정렬된 vector가 된다. (규칙 2)
    vector<int> answer(tmp_result.begin(), tmp_result.end());

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({2, 1, 3, 4, 1}), vector<int>{2, 3, 4, 5, 6, 7});
    t.check(solution({5, 0, 2, 7}), vector<int>{2, 5, 7, 9, 12});

    // 아래는 직접 추가한 경계 케이스
    t.check("최소 길이 2", solution({1, 2}), vector<int>{3});
    t.check("값이 전부 같음", solution({3, 3, 3}), vector<int>{6});
    t.check("음수 없음·0 포함", solution({0, 0, 1}), vector<int>{0, 1});
    return t.report();
}
