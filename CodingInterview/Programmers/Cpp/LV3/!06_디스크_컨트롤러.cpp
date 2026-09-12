// https://school.programmers.co.kr/learn/courses/30/lessons/42627?language=cpp
// 출처: 힙
// 대응 Python 풀이: ../../Python/LV3/!06_디스크_컨트롤러.py

// Number of times solving questions: 0
// 2026-00-00

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
// 필요한 헤더는 직접 추가할 것 (<algorithm> sort/min_element, <numeric> accumulate,
// <sstream> stringstream, <unordered_map>, <unordered_set>, <set>, <stdexcept> runtime_error)
#include <string>
#include <vector>
using namespace std;

// TODO: 프로그래머스 C++ 답안지 스켈레톤의 시그니처를 그대로 옮겨 적을 것.
// TODO: Python 풀이의 "규칙 -> 의도" 주석을 먼저 읽고 같은 로직을 STL로 옮긴다.
//       list -> vector, dict -> unordered_map, set -> unordered_set, sorted() -> sort()


// ─────────────────────────────────────────────────────────────
// 2026-09-12 착수 · 접근 골격까지 세우고 보류 (LV2 보강 후 재개)
// ─────────────────────────────────────────────────────────────
// 요청 시간 순으로 정렬
//
// while 남은 작업 있음
//     while 현재 시각까지 요청된 작업이 있음
//         대기열(힙)에 넣기
//         idx++
//     if 대기열에 작업 있음
//         하나 꺼내 실행          ← 어느 것을 꺼낼지가 이 문제의 전부
//         현재 시각 += 소요 시간
//         대기시간 누적 (= 끝난 시각 - 요청 시각)
//     else
//         현재 시각을 다음 요청 시각으로 점프
//
// return 대기시간 합 / 작업 수
//
// 남은 질문: 예제 [[0,3],[1,9],[2,6]] 에서 3ms 시점에 B(9ms)와 C(6ms)가 함께 대기 중이다.
//            어느 쪽을 먼저 하면 평균이 짧아지는가? -> 그 답이 힙의 정렬 기준이 된다.

int main() {
    Tester t("solution");
    // TODO: Python 파일의 test_cases 와 같은 입력으로 t.check(...) 를 채울 것
    //   예) t.check(solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}}), vector<int>{5});
    return t.report();
}
