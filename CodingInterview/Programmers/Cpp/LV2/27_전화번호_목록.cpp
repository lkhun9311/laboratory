// https://school.programmers.co.kr/learn/courses/30/lessons/42577?language=cpp
// 출처: 해시
// 대응 Python 풀이: ../../Python/LV2/!27_전화번호_목록.py

// Number of times solving questions: 1
// 2026-09-19
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    int n = phone_book.size();
    int p_i_size;

    for (int i=0; i<n-1; i++) {
        p_i_size = phone_book[i].size();
        if (phone_book[i] == phone_book[i+1].substr(0, p_i_size)) {
            return false;
        }
    }

    return true;
}

int main() {
    Tester t("solution");
    t.check(solution({"119", "97674223", "1195524421"}), false);
    t.check(solution({"123", "456", "789"}), true);
    t.check(solution({"12", "123", "1235", "567", "88"}), false);

    // 아래는 직접 추가한 경계 케이스
    t.check("번호 하나", solution({"119"}), true);
    t.check("같은 번호 두 개", solution({"12", "12"}), false);
    t.check("접두어가 아니라 끝부분만 같다", solution({"113", "13"}), true);
    t.check("정렬하면 붙지 않는 접두어", solution({"1", "2", "3", "11"}), false);
    return t.report();
}
