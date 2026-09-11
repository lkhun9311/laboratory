// https://school.programmers.co.kr/learn/courses/30/lessons/42586?language=cpp
// 출처: 스택/큐
// 대응 Python 풀이: ../../Python/LV2/34_기능개발.py

// Number of times solving questions: 1
// 2026-09-11

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 규칙 1. 진도가 100 이상이 되면 그 기능은 완성된다.
    // 규칙 2. 배포는 앞에서부터만 된다. 뒤 기능이 먼저 끝나도 앞 기능을 기다린다.
    // 규칙 3. 한 번에 배포되는 기능의 개수를 순서대로 담아 반환한다.

    vector<int> answer;
    vector<int> days;
    int progresses_size = progresses.size();

    // 1단계. 각 작업이 며칠 걸리는지 구한다.
    //
    // 정수 나눗셈은 소수점을 버리므로 그냥 need / speed 를 쓰면 안 된다.
    // 진도 30%, 하루 30 이면 70/30 == 2 가 나오지만 실제로는 3일째에 100을 넘는다(30->60->90->120).
    // (need + speed - 1) / speed 가 올림 나눗셈 관용구다: (70 + 29) / 30 == 3.
    // ceil() 은 double 을 거쳐 오차 위험이 있어 정수 문제에서는 이 관용구를 쓴다.
    for (int i = 0; i < progresses_size; i++) {
        int need = 100 - progresses[i];
        int day = (need + speeds[i] - 1) / speeds[i];
        days.push_back(day);
    }

    // 2단계. 일수 배열을 그룹으로 나눈다.
    //
    // 앞 작업이 끝나야 뒤가 나가므로, 한 그룹의 배포일은 "그 그룹의 첫 작업이 걸리는 날"이다. (규칙 2)
    // 뒤 작업의 일수가 그 날보다 작거나 같으면 이미 끝나 있으니 함께 나가고,
    // 크면 그날 못 나가므로 거기서 새 그룹이 시작된다.
    //
    // 큐는 필요 없다. 한 번 지나간 작업을 다시 볼 일이 없어 쌓아둘 것이 없기 때문이다.
    // (28번 햄버거는 빼낸 뒤 그 아래가 다시 검사 대상이라 스택이 진짜로 필요했다 - 대비해서 기억할 것)
    int days_size = days.size();
    int deployDay = days[0];    // 현재 그룹의 배포일. 작업이 1개 이상임이 보장된다
    int count = 1;              // 현재 그룹에 묶인 개수

    for (int i = 1; i < days_size; i++) {
        if (deployDay >= days[i]) {
            count++;
        } else {
            answer.push_back(count);    // 그룹이 끝났으니 확정한다
            count = 1;
            deployDay = days[i];
        }
    }

    // 루프는 "새 그룹이 시작될 때" 직전 그룹을 확정하므로 마지막 그룹은 확정되지 않은 채 끝난다.
    // 23번 문자열 나누기에서 겪은 것과 같은 자리다. 여기서는 루프 뒤 한 줄로 처리한다. (규칙 3)
    answer.push_back(count);

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({93, 30, 55}, {1, 30, 5}), vector<int>{2, 1});
    t.check(solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1}), vector<int>{1, 3, 2});

    // 아래는 직접 추가한 경계 케이스
    t.check("작업 1개", solution({50}, {10}), vector<int>{1});
    t.check("앞이 가장 느려 전부 함께", solution({10, 20, 30}, {1, 1, 1}), vector<int>{3});
    t.check("뒤로 갈수록 느려 전부 따로", solution({30, 20, 10}, {1, 1, 1}), vector<int>{1, 1, 1});
    t.check("올림 필요(30%, 하루 30 -> 3일)", solution({30, 30}, {30, 50}), vector<int>{2});
    t.check("같은 날 완성", solution({90, 90}, {10, 10}), vector<int>{2});
    return t.report();
}
