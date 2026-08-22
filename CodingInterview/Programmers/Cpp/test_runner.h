// Python 쪽 test_runner.py 와 같은 표를 출력하는 C++ 채점 헤더.
//
// 사용법
//   #include "../test_runner.h"
//
//   vector<int> solution(vector<int> array, vector<vector<int>> commands) { ... }
//
//   int main() {
//       Tester t("solution");
//       t.check(solution({1,5,2,6,3,7,4}, {{2,5,3},{4,4,1}}), vector<int>{5, 6});
//       t.check("동명이인", solution({...}), vector<int>{...});   // 라벨을 직접 줄 수도 있다
//       return t.report();
//   }
//
// 빌드·실행
//   ./run.sh LV1/'!53_완주하지_못한_선수.cpp'
//   또는  g++ -std=c++20 -O2 <파일> -o /tmp/a && /tmp/a
//
// report()는 전부 통과하면 0, 아니면 1을 반환하므로 그대로 main의 반환값으로 쓴다.

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <sstream>

namespace tr {

inline const char* GREEN = "\033[92m";
inline const char* RED   = "\033[91m";
inline const char* RESET = "\033[0m";

// ── 값을 파이썬 repr 처럼 문자열로 만든다 ────────────────────────

inline std::string repr(bool v)               { return v ? "True" : "False"; }
inline std::string repr(int v)                { return std::to_string(v); }
inline std::string repr(long v)               { return std::to_string(v); }
inline std::string repr(long long v)          { return std::to_string(v); }
inline std::string repr(unsigned v)           { return std::to_string(v); }
inline std::string repr(unsigned long long v) { return std::to_string(v); }
inline std::string repr(char v)               { return "'" + std::string(1, v) + "'"; }

inline std::string repr(double v) {
    std::ostringstream os;
    os << std::setprecision(15) << v;
    return os.str();
}

inline std::string repr(const std::string& v) { return "'" + v + "'"; }
inline std::string repr(const char* v)        { return "'" + std::string(v) + "'"; }

template <typename T> std::string repr(const std::vector<T>& v);
template <typename A, typename B> std::string repr(const std::pair<A, B>& p);

// 원소를 쉼표로 이어 붙이는 공통 처리
template <typename It>
std::string join(It first, It last, const char* open, const char* close) {
    std::string s = open;
    for (It it = first; it != last; ++it) {
        if (it != first) s += ", ";
        s += repr(*it);
    }
    return s + close;
}

template <typename T>
std::string repr(const std::vector<T>& v) { return join(v.begin(), v.end(), "[", "]"); }

template <typename T>
std::string repr(const std::set<T>& v) { return join(v.begin(), v.end(), "{", "}"); }

template <typename A, typename B>
std::string repr(const std::pair<A, B>& p) {
    return "(" + repr(p.first) + ", " + repr(p.second) + ")";
}

// ── 표 폭 계산: 한글은 두 칸을 차지한다 ──────────────────────────

inline int width(const std::string& s) {
    int w = 0;
    for (size_t i = 0; i < s.size();) {
        unsigned char c = s[i];
        if (c < 0x80)      { i += 1; w += 1; }
        else if (c < 0xE0) { i += 2; w += 1; }
        else if (c < 0xF0) { i += 3; w += 2; }   // 한글·CJK
        else               { i += 4; w += 2; }
    }
    return w;
}

inline std::string pad(const std::string& s, int w) {
    return s + std::string(std::max(0, w - width(s)), ' ');
}

// ── 채점기 ────────────────────────────────────────────────────

class Tester {
public:
    explicit Tester(std::string label = "solution") : label_(std::move(label)) {}

    // 라벨을 생략하면 "예제 1", "예제 2" … 로 자동으로 붙는다.
    template <typename T, typename U>
    void check(const T& actual, const U& expected) {
        check("예제 " + std::to_string(rows_.size() + 1), actual, expected);
    }

    template <typename T, typename U>
    void check(const std::string& name, const T& actual, const U& expected) {
        bool ok = (actual == static_cast<T>(expected));
        if (ok) ++passed_;
        rows_.push_back({ok, name, repr(expected), repr(actual)});
    }

    int report() {
        // 아직 입출력 예를 안 채운 스텁은 여기로 온다. 통과로 착각하지 않도록 실패를 반환한다.
        if (rows_.empty()) {
            std::cout << "[ " << label_ << " ]\n"
                      << "  TODO: check() 가 하나도 없습니다. 문제의 입출력 예를 채워 넣으세요.\n";
            return 1;
        }

        const std::vector<std::string> head = {"OK", "CASE", "EXPECTED", "ACTUAL"};
        std::vector<int> w(4);
        for (size_t i = 0; i < 4; ++i) w[i] = width(head[i]);
        for (const Row& r : rows_) {
            w[0] = std::max(w[0], 1);
            w[1] = std::max(w[1], width(r.name));
            w[2] = std::max(w[2], width(r.expected));
            w[3] = std::max(w[3], width(r.actual));
        }

        std::string line = "+";
        for (int x : w) line += std::string(x + 2, '-') + "+";

        std::cout << "[ " << label_ << " ]\n" << line << "\n|";
        for (size_t i = 0; i < 4; ++i) std::cout << " " << pad(head[i], w[i]) << " |";
        std::cout << "\n" << line << "\n";

        for (const Row& r : rows_) {
            std::string mark = r.ok ? "O" : "X";
            std::cout << "| " << (r.ok ? GREEN : RED) << pad(mark, w[0]) << RESET << " |"
                      << " " << pad(r.name,     w[1]) << " |"
                      << " " << pad(r.expected, w[2]) << " |"
                      << " " << pad(r.actual,   w[3]) << " |\n";
        }
        std::cout << line << "\n";

        bool all = passed_ == static_cast<int>(rows_.size());
        std::cout << (all ? GREEN : RED) << "PASS: " << passed_ << "/" << rows_.size()
                  << RESET << "\n";
        return all ? 0 : 1;
    }

private:
    struct Row { bool ok; std::string name, expected, actual; };
    std::string label_;
    std::vector<Row> rows_;
    int passed_ = 0;
};

}  // namespace tr

using tr::Tester;
