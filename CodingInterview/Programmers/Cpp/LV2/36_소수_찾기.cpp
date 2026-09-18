// https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=cpp
// 출처: 완전탐색
// 대응 Python 풀이: ../../Python/LV2/!36_소수_찾기.py

// Number of times solving questions: 1
// 2026-09-18
// 소요 시간: -

#include "../test_runner.h"
// 아래는 프로그래머스 제출 코드와 동일하게 유지한다.
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(string& current, int numbersSize, const string& numbers, unordered_set<int>& setNumbers, vector<bool>& visited) {
    for (int i=0; i<numbersSize; i++) {
        if (visited[i]) {
            continue;
        }

        current.push_back(numbers[i]);
        visited[i] = true;
        setNumbers.insert(stoi(current));
        dfs(current, numbersSize, numbers, setNumbers, visited);

        current.pop_back();
        visited[i] = false;
    }
}

bool isPrime(int number) {
    if (number<2) {
        return false;
    }

    for (int n=2; n*n<=number; n++) {
        if (number%n == 0) {
            return false;
        }
    }

    return true;
}

int solution(string numbers) {
    int answer = 0;
    string current = "";
    int numbersSize = numbers.size();
    unordered_set<int> setNumbers;
    vector<bool> visited(numbersSize, false);


    dfs(current, numbersSize, numbers, setNumbers, visited);

    for (int number : setNumbers) {
        if (isPrime(number)) {
            answer++;
        }
    }

    return answer;
}

int main() {
    Tester t("solution");
    t.check(solution("17"), 3);
    t.check(solution("011"), 2);

    // 아래는 직접 추가한 경계 케이스 (손으로 만들 수 있는 수를 모두 적어 확인했다)
    t.check("한 자리, 소수 아님 (0)", solution("0"), 0);
    t.check("한 자리, 소수 아님 (1)", solution("1"), 0);
    t.check("한 자리, 소수 (2)", solution("2"), 1);
    t.check("11 -> {1, 11} 중 11 만 소수", solution("11"), 1);
    t.check("10 -> {0, 1, 10} 소수 없음", solution("10"), 0);
    t.check("07 -> {0, 7, 70} 중 7 만 소수", solution("07"), 1);
    return t.report();
}
