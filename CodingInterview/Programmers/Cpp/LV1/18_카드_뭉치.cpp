// https://school.programmers.co.kr/learn/courses/30/lessons/159994?language=cpp
// 출처: 연습문제
// 대응 Python 풀이: ../../Python/LV1/18_카드_뭉치.py

// Number of times solving questions: 1
// 2026-09-07

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    // 규칙 1. 카드는 뭉치의 맨 위에서만 뽑는다. 건너뛰거나 버릴 수 없다.
    //         따라서 실제로 쓰이는 카드는 언제나 뭉치의 "앞에서부터 이어진 구간"이다.
    // 규칙 2. 뭉치를 끝까지 다 쓸 필요는 없다. goal을 채우면 나머지는 남겨도 된다.
    // 규칙 3. cards1과 cards2에는 서로 다른 단어만 존재한다.
    //         이 한 줄이 난이도를 결정한다 — 어떤 단어를 지금 낼 수 있는 뭉치는 많아야 하나뿐이라
    //         "어느 쪽에서 뽑을까" 하는 갈림길이 아예 생기지 않는다.
    //         (같은 단어가 양쪽에 있을 수 있었다면 되돌아가 다시 고르는 백트래킹이 필요해진다.)

    // 뭉치를 실제로 깎지 않고 맨 위가 몇 번째인지만 기억한다. (규칙 1)
    int cards1_index = 0;
    int cards2_index = 0;

    // size()는 unsigned라 int와 직접 비교하면 -Wsign-compare 경고가 난다.
    // int로 한 번 받아두면 경고도 없고, 인덱스가 음수로 내려가는 문제에서도 비교가 깨지지 않는다.
    int cards1_size = cards1.size();
    int cards2_size = cards2.size();

    // goal을 앞에서부터 한 단어씩 확정한다. 선택지가 없으므로 (규칙 3)
    // 되돌아가지 않고 한 번의 순회로 판정이 끝난다.
    for (const string& g : goal) {
        // 뭉치가 바닥나면 맨 위 카드라는 게 존재하지 않는다.
        // and(=&&)는 왼쪽이 거짓이면 오른쪽을 평가하지 않으므로,
        // 범위 검사를 왼쪽에 두어 벡터 범위 밖 접근을 막는다. (규칙 2)
        if (cards1_index < cards1_size and cards1[cards1_index] == g) {
            cards1_index += 1;
        } else if (cards2_index < cards2_size and cards2[cards2_index] == g) {
            cards2_index += 1;
        } else {
            // 두 맨 위 카드 어느 쪽도 아니면 이 단어는 영영 나올 수 없다.
            // 이 단어를 덮고 있는 카드를 치울 방법이 없기 때문이다. (규칙 1)
            return "No";
        }
    }

    return "Yes";
}

int main() {
    Tester t("solution");
    t.check(solution({"i", "drink", "water"}, {"want", "to"},
                     {"i", "want", "to", "drink", "water"}), string("Yes"));
    t.check(solution({"i", "water", "drink"}, {"want", "to"},
                     {"i", "want", "to", "drink", "water"}), string("No"));

    // 아래는 직접 추가한 경계 케이스 (Python 쪽과 동일)
    t.check(solution({"a", "b"}, {"c", "d"}, {"b", "c"}), string("No"));
    t.check(solution({"a"}, {"b"}, {"a", "b"}), string("Yes"));
    t.check(solution({"a", "b"}, {"c", "d"}, {"a", "c"}), string("Yes"));
    t.check(solution({"a", "b"}, {"c", "d"}, {"a", "d"}), string("No"));
    return t.report();
}
