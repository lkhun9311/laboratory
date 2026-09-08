// https://school.programmers.co.kr/learn/courses/30/lessons/12906?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/85_같은_숫자는_싫어.py

// Number of times solving questions: 1
// 2026-09-08

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
    // 규칙 1. 연속해서 같은 수가 나오면 하나만 남긴다. 떨어져 있는 중복은 남긴다.
    // 규칙 2. 남은 수들의 원래 순서는 그대로 유지한다.

    vector<int> answer;

    // size()는 unsigned라 int와 직접 비교하면 -Wsign-compare 경고가 난다. int로 받아둔다.
    int arr_size = arr.size();

    // 결과는 아무리 많아도(전부 다른 수여도) 입력 개수를 넘지 않는다.
    // 상한을 미리 알려주면 push_back 도중의 재할당·복사가 사라진다. (100만 원소 기준 실측 2배)
    answer.reserve(arr_size);

    // 각 원소를 "바로 뒤 원소와 다른가"로 판정한다.
    // 같으면 연속 중복이므로 버리고, 다르면 그 자리에서 하나가 끝났다는 뜻이라 남긴다. (규칙 1)
    for (int i=0; i<arr_size-1; i++) {
        if (arr[i] != arr[i+1]) {
            answer.push_back(arr[i]);
        }
    }

    // 마지막 원소는 비교할 다음 원소가 없어 위 루프가 판정할 수 없다.
    // 동시에 뒤에 아무것도 없으므로 연속 중복일 수도 없다 → 조건 없이 항상 포함한다. (규칙 1)
    // 길이 1인 입력은 루프가 0번 돌고 이 줄만 실행되어 그대로 답이 된다.
    answer.push_back(arr.back());

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1, 1, 3, 3, 0, 1, 1}), vector<int>{1, 3, 0, 1});
    t.check(solution({4, 4, 4, 3, 3}), vector<int>{4, 3});

    // 아래는 직접 추가한 경계 케이스
    t.check("길이 1", solution({5}), vector<int>{5});
    t.check("전부 같음", solution({7, 7, 7, 7}), vector<int>{7});
    t.check("전부 다름", solution({1, 2, 3}), vector<int>{1, 2, 3});
    t.check("끝이 중복", solution({1, 2, 2}), vector<int>{1, 2});
    return t.report();
}
