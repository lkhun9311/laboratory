// https://school.programmers.co.kr/learn/courses/30/lessons/135808?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/26_과일_장수.py

// Number of times solving questions: 1
// 2026-09-13

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>    // sort. 스켈레톤에 없으므로 직접 추가한다
using namespace std;

int solution(int k, int m, vector<int> score) {
    // 규칙 1. m개씩 한 상자로 묶고, 상자 가격 = (그 상자의 최저 점수) * m.
    // 규칙 2. 남는 사과는 버린다. 최대 이익을 구한다.
    //
    // 그리디 근거: 상자 가격은 "그 상자의 최솟값"에만 좌우된다.
    //   점수가 크게 차이 나는 사과를 한 상자에 담으면 높은 사과가 낮은 최솟값에 끌려가 낭비된다.
    //   따라서 비슷한 점수끼리 묶어야 하고, 정렬하면 그것이 저절로 된다.
    //   내림차순으로 앞에서부터 m개씩 끊으면 각 상자의 최솟값은 그 묶음의 마지막 원소다.
    //   남는 사과는 가장 점수가 낮은 것들이므로 버려도 손해가 없다. (규칙 2)

    int result = 0;

    // rbegin/rend 는 뒤에서 앞으로 가는 이터레이터다. 이걸 sort 에 주면 내림차순이 된다.
    // (비교 함수 greater<int>() 를 넘기는 것과 같은 결과)
    sort(score.rbegin(), score.rend());

    int box_count = score.size() / m;       // 만들 수 있는 상자 수. 나머지는 버린다

    for (int t = 0; t < box_count; t++) {
        int min_value = score[(t + 1) * m - 1];     // t번째 묶음의 마지막 = 그 상자의 최솟값
        result += m * min_value;                    // (규칙 1)
    }

    return result;
}

int main() {
    Tester t("solution");
    t.check(solution(3, 4, {1, 2, 3, 1, 2, 3, 1}), 8);
    t.check(solution(4, 3, {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2}), 33);

    // 아래는 직접 추가한 경계 케이스
    t.check("한 상자도 못 채움", solution(3, 4, {1, 2}), 0);
    t.check("딱 한 상자", solution(3, 2, {2, 3}), 4);
    t.check("전부 같은 점수", solution(3, 2, {3, 3, 3, 3}), 12);
    return t.report();
}
