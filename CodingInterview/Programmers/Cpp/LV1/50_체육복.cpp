// https://school.programmers.co.kr/learn/courses/30/lessons/42862?language=cpp
// 출처: 탐욕법(Greedy)
// 대응 Python 풀이: ../../Python/LV1/50_체육복.py

// Number of times solving questions: 1
// 2026-09-09

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <set>          // 스켈레톤에 없다. 직접 추가해야 한다.
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // 규칙 1. 여벌이 있는 학생은 바로 앞/뒤 번호(±1)에게만 빌려줄 수 있다.
    // 규칙 2. 여벌을 가져왔는데 자기 것도 도난당한 학생은 자기 여벌을 입어야 하므로 빌려줄 수 없다.
    //         이 학생은 "빌릴 필요도, 빌려줄 여력도" 없는 상태다.
    // 규칙 3. 수업을 들을 수 있는 학생 수의 최댓값을 구한다.

    set<int> lostSet(lost.begin(), lost.end());
    set<int> reserveSet(reserve.begin(), reserve.end());

    // 규칙 2의 학생을 양쪽에서 동시에 지운다.
    // 한쪽만 지우면 "빌려줄 수 없는데 빌려주거나", "이미 입었는데 또 빌리는" 오답이 난다.
    for (int r : reserve) {
        if (lostSet.count(r)) {
            lostSet.erase(r);
            reserveSet.erase(r);
        }
    }

    // 낮은 번호부터 돌며 왼쪽(r-1) 먼저, 없으면 오른쪽(r+1)에게 빌려준다.
    //
    // 왜 왼쪽 먼저인가 (교환 논증):
    //   지금 보는 r 이 남은 giver 중 가장 작은 번호다.
    //   r-1 을 도울 수 있는 사람은 r-2 와 r 뿐인데, r 보다 작은 giver 는 없으므로
    //   r-2 는 giver 가 아니다 -> r-1 은 r 말고는 구할 사람이 없다.
    //   반면 r+1 은 r+2 가 구해줄 수도 있다.
    //   대안이 없는 쪽부터 주는 것이 절대 손해가 아니다.
    //   (오른쪽 우선으로 바꾸면 n=4, lost=[1,3], reserve=[2,4] 에서 4가 아니라 3이 나온다)
    //
    // 이 논증은 "가장 작은 giver 부터 본다"를 전제로 한다.
    // set 은 순회가 항상 오름차순이라 정렬이 이미 돼 있다.
    // unordered_set 으로 바꾸면 순서 보장이 사라져 같은 로직이 틀린다 (랜덤 15만 건 중 1,078건 오답).
    for (int r : reserveSet) {
        if (lostSet.count(r-1)) {
            lostSet.erase(r-1);
        } else if (lostSet.count(r+1)) {
            lostSet.erase(r+1);
        }
    }

    // 끝내 빌리지 못한 학생만 수업을 못 듣는다. (규칙 3)
    return n - lostSet.size();
}

int main() {
    Tester t("solution");
    t.check(solution(5, {2, 4}, {1, 3, 5}), 5);
    t.check(solution(5, {2, 4}, {3}), 4);
    t.check(solution(3, {3}, {1}), 2);

    // 아래는 직접 추가한 경계 케이스
    t.check("왼쪽 우선이어야 최적", solution(4, {1, 3}, {2, 4}), 4);
    t.check("여벌+도난 겹침(빌려줄 수 없음)", solution(3, {1, 2}, {2, 3}), 2);
    t.check("빌릴 이웃이 없음", solution(5, {1}, {5}), 4);
    t.check("전원 도난, 전원 여벌", solution(3, {1, 2, 3}, {1, 2, 3}), 3);
    return t.report();
}
