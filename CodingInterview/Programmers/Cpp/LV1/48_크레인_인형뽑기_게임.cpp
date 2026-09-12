// https://school.programmers.co.kr/learn/courses/30/lessons/64061?language=cpp
// 출처: 2019 카카오 개발자 겨울 인턴십
// 대응 Python 풀이: ../../Python/LV1/48_크레인_인형뽑기_게임.py

// Number of times solving questions: 1
// 2026-09-12

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    // 규칙 1. board 는 위에서 아래로 쌓인 격자다. 0 은 빈 칸.
    // 규칙 2. moves[i] 번째 "열"에서 가장 위 인형 하나를 집어 바구니에 담는다.
    //         빈 열을 집으면 아무 일도 일어나지 않는다.
    // 규칙 3. 바구니에 같은 인형이 연속 두 개가 되면 둘 다 사라진다.
    //         사라지면 그 아래 인형이 새 맨 위가 되어 다음 인형과 다시 비교된다
    //         -> 다시 꺼내 볼 일이 있다 = 스택이 맞다 (28번 햄버거와 같은 구조).
    // 규칙 4. 터진 인형의 총 개수를 반환한다 (2개씩 터지므로 짝수).

    int answer = 0;
    int rows = board.size();
    int cols = board[0].size();

    // 열마다 스택을 미리 만들어 둔다. 매번 격자를 위에서부터 훑지 않아도 된다.
    // 스택 개수는 열 개수다 (정사각 격자라 rows 로 써도 우연히 동작하지만 의미가 다르다).
    vector<vector<int>> stacks(cols);

    // 아래 행부터 넣으므로 back() 이 곧 "가장 위 인형"이 된다.
    for (int col = 0; col < cols; col++) {
        for (int row = rows - 1; row >= 0; row--) {
            int doll = board[row][col];
            if (doll != 0) {
                stacks[col].push_back(doll);
            }
        }
    }

    vector<int> basket;

    for (int move : moves) {
        // 참조로 잡아야 pop_back 이 실제 스택에 반영된다.
        // (43번의 "auto& 금지"와 반대 상황이다. 거기서는 참조가 가리키던 원소가 사라졌고,
        //  여기서는 컨테이너 자체를 고치려고 참조를 잡는다. 기준은 "참조 대상이 사라지는가".)
        vector<int>& tmp_stack = stacks[move - 1];

        if (tmp_stack.empty()) {
            continue;               // 빈 열 (규칙 2)
        }

        int doll = tmp_stack.back();
        tmp_stack.pop_back();

        if (!basket.empty() && basket.back() == doll) {
            basket.pop_back();      // 둘 다 사라진다 (규칙 3)
            answer += 2;
        } else {
            basket.push_back(doll);
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({{0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 3},
                      {0, 2, 5, 0, 1},
                      {4, 2, 4, 4, 2},
                      {3, 5, 1, 3, 1}},
                     {1, 5, 3, 5, 1, 2, 1, 4}), 4);

    // 아래는 직접 추가한 경계 케이스 (검증된 구현으로 기대값을 계산했다)
    t.check("전부 빈 격자", solution(vector<vector<int>>(5, vector<int>(5, 0)), {1, 2, 3, 4, 5}), 0);
    t.check("인형 1개를 두 번 집기",
            solution({{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,0,0,0,0}}, {1, 1}), 0);
    t.check("같은 인형 2개가 터짐",
            solution({{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{1,1,0,0,0}}, {1, 2}), 2);
    t.check("터진 뒤 아래 것과 다시 만남",
            solution({{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{2,0,0,0,0},{1,1,2,0,0}}, {1, 2, 1, 3}), 4);
    return t.report();
}
