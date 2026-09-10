// https://school.programmers.co.kr/learn/courses/30/lessons/12969?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/58_직사각형_별찍기.py

// Number of times solving questions: 1
// 2026-09-10

// ※ 이 문제만 프로그래머스가 solution 함수가 아니라 main + cin/cout 형태로 준다.
//    실제 제출 코드는 파일 맨 아래 주석에 있다.
//    여기서는 채점을 위해 Python 쪽과 같이 "직사각형 문자열을 반환하는" 형태로 맞춘다.

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

string solution(int width, int height) {
    // 규칙 1. 한 줄에 '*'를 width개, 그런 줄을 height개 만든다.
    // 규칙 2. 줄 사이에만 개행을 넣는다 (맨 끝에는 붙이지 않는다).

    string answer;

    // 최종 길이가 정확히 계산된다: 별 width*height개 + 줄 사이 개행 (height-1)개.
    // 잡은 만큼 전부 채우므로 reserve가 확실히 이득이다.
    // (28번 햄버거처럼 실제로 안 채우는 경우에는 오히려 손해였다 - 상황이 성능을 정한다)
    answer.reserve((size_t)width * height + height);

    // 별을 하나씩 붙이지 않고 한 줄을 통째로 만들어 둔다.
    // string(n, c)는 문자 c를 n개 가진 문자열을 한 번에 만든다 (Python의 "*" * n).
    // 1000x1000 실측: 하나씩 0.748ms -> 줄 단위 0.024ms -> reserve까지 0.010ms
    const string line(width, '*');

    // 개행을 "각 줄 뒤"가 아니라 "첫 줄을 제외한 각 줄 앞"에 넣어야 끝에 여분이 안 생긴다. (규칙 2)
    for (int i = 0; i < height; i++) {
        if (i > 0) {
            answer += '\n';
        }
        answer += line;
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check("5 x 3", solution(5, 3), string("*****\n*****\n*****"));

    // 아래는 직접 추가한 경계 케이스
    t.check("1 x 1", solution(1, 1), string("*"));
    t.check("3 x 1", solution(3, 1), string("***"));
    t.check("1 x 3", solution(1, 3), string("*\n*\n*"));
    return t.report();
}

// ─────────────────────────────────────────────────────────────
// 실제 프로그래머스 제출 형태 (main + cin/cout)
// ─────────────────────────────────────────────────────────────
//   #include <iostream>
//   #include <string>
//   using namespace std;
//
//   int main() {
//       int width, height;
//       cin >> width >> height;
//
//       string answer;
//       answer.reserve((size_t)width * height + height);
//       const string line(width, '*');
//       for (int i = 0; i < height; i++) {
//           answer += line;
//           answer += '\n';       // 제출본은 끝 개행이 있어도 통과한다
//       }
//
//       cout << answer;           // endl은 개행 + flush다. 여기선 flush가 불필요하고,
//                                 // answer가 이미 개행으로 끝나므로 그냥 출력한다.
//       return 0;
//   }
