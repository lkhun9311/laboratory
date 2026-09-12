// https://school.programmers.co.kr/learn/courses/30/lessons/12977?language=cpp
// 출처: 연습문제 (Summer/Winter Coding 2018)
// 대응 Python 풀이: ../../Python/LV1/57_소수_만들기.py

// Number of times solving questions: 1
// 2026-09-12
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <cmath>        // sqrt. 스켈레톤에 없으므로 직접 추가한다
using namespace std;

int solution(vector<int> nums) {
    // 규칙 1. nums 에서 서로 다른 3개를 골라 더한 값이 소수인 경우의 수를 센다.
    // 규칙 2. nums 길이 3~50, 원소 1~1,000, 중복 없음.
    //         고르는 경우의 수는 최대 C(50,3) = 19,600 이라 삼중 루프로 충분하다.
    //         합의 최댓값은 1000*3 = 3,000 이므로 int 로 충분하다.

    int answer = 0;
    int n = nums.size();

    // j 는 i+1 부터, k 는 j+1 부터 시작해 "서로 다른 3개"를 중복 없이 한 번씩만 고른다.
    // (i, j, k) 와 (j, i, k) 를 따로 세지 않기 위해서다. (규칙 1)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int total = nums[i] + nums[j] + nums[k];

                // 소수 판정: 2 부터 sqrt(total) 까지만 나눠 본다.
                //
                // total = a * b 라면 둘 중 하나는 반드시 sqrt(total) 이하다.
                // 따라서 sqrt 까지 훑어 약수가 없으면 그 위에도 없다. O(total) -> O(sqrt(total)).
                //
                // limit 을 sqrt(total) + 1 로 잡아야 total 이 완전제곱수일 때(9, 25, 49 ...)
                // 제곱근 자신을 검사한다. 이 +1 이 없으면 9, 25 를 소수로 잘못 판정한다.
                // (합의 범위 6~3000 전체를 무식한 판정과 대조해 확인했다)
                bool is_prime = true;
                int limit = sqrt(total) + 1;

                for (int divisor = 2; divisor < limit; divisor++) {
                    if (total % divisor == 0) {
                        is_prime = false;
                        break;      // 약수를 하나 찾으면 더 볼 것 없다
                    }
                }

                if (is_prime) {
                    answer += 1;
                }
            }
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution({1, 2, 3, 4}), 1);
    t.check(solution({1, 2, 7, 6, 4}), 4);

    // 아래는 직접 추가한 경계 케이스 (검증된 구현으로 기대값을 계산했다)
    t.check("최소 크기 3개, 합 6 = 소수 아님", solution({1, 2, 3}), 0);
    t.check("최소 크기 3개, 합이 소수", solution({1, 2, 4}), 1);
    t.check("합 9(완전제곱수)가 섞임", solution({2, 3, 4, 5}), 1);
    t.check("전부 홀수", solution({1, 3, 5, 7, 9}), 6);
    return t.report();
}
