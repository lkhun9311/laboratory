# ─────────────────────────────────────────────────────────────
# 공통 테스트 러너
# ─────────────────────────────────────────────────────────────
# 각 문제 파일에서 import해서 테스트 결과를 표로 출력하는 공용 모듈.
#
# 사용법:
#   from test_runner import run_tests
#
#   # 1) 풀이가 하나일 때
#   run_tests(solution, [(입력, 기대값), ...])
#
#   # 2) 풀이가 여러 개일 때 (리스트 또는 dict)
#   run_tests([solution1, solution2], [(입력, 기대값), ...])
#   run_tests({"슬라이싱": solution1, "산술": solution2}, [...])
#     → 함수마다 '독립된 표'를 함수 이름과 함께 출력하고,
#       표와 표 사이는 빈 줄 3칸으로 구분한다.
#       리스트로 주면 함수 이름(__name__)이, dict로 주면 key가 라벨이 된다.
#
# - 입력이 tuple이면 여러 인자로 풀어서 호출한다: solution(*입력)
#   (예: 별찍기 처럼 인자가 2개인 문제 → ((5, 3), "...") 형태로 작성)
#   그 외에는 단일 인자로 호출한다: solution(입력)
# - 머리글·테두리가 모두 ASCII라서 폰트/터미널과 무관하게 정렬이 항상 맞는다.
# - 정답은 초록 O, 오답은 빨강 X로 표시하고 각 표 끝에 PASS 요약을 낸다.

GREEN = "\033[92m"  # 초록
RED = "\033[91m"    # 빨강
RESET = "\033[0m"   # 색상 초기화
GAP = "\n"  # 표 사이 구분 (빈 줄 3칸)

def _print_one(label, fn, test_cases):
    """함수 하나에 대한 결과 표를 함수 이름(label)과 함께 출력한다."""
    headers = ["OK", "INPUT", "EXPECTED", "ACTUAL"]

    # 아직 입출력 예를 안 채운 스텁 파일은 여기로 온다. 표를 만들려 하면 터지므로 먼저 걸러낸다.
    if not test_cases:
        print(f"[ {label} ]")
        print("  TODO: test_cases 가 비어 있습니다. 문제의 입출력 예를 채워 넣으세요.")
        print("        인자가 여러 개면 반드시 tuple 로 감쌉니다.")
        return False

    # 표 행 데이터: (mark, [셀, ...]) — 전부 repr이라 ASCII 문자열
    rows = []
    pass_count = 0
    for inp, expected in test_cases:
        actual = fn(*inp) if isinstance(inp, tuple) else fn(inp)
        ok = actual == expected
        pass_count += ok
        mark = "O" if ok else "X"
        rows.append((mark, [mark, repr(inp), repr(expected), repr(actual)]))

    # 각 열 너비 = 머리글과 데이터 중 가장 긴 것 (전부 ASCII이므로 len 그대로)
    widths = [max(len(headers[i]), *(len(r[1][i]) for r in rows)) for i in range(len(headers))]

    def make_line():
        return "+" + "+".join("-" * (w + 2) for w in widths) + "+"

    def make_row(cells, mark=None):
        out = []
        for i, cell in enumerate(cells):
            padded = cell.ljust(widths[i])
            if mark and i == 0:  # OK 칸만 색칠 (색 코드는 ljust 이후라 폭에 영향 없음)
                padded = (GREEN if mark == "O" else RED) + padded + RESET
            out.append(" " + padded + " ")
        return "|" + "|".join(out) + "|"

    print(f"[ {label} ]")
    print(make_line())
    print(make_row(headers))
    print(make_line())
    for mark, cells in rows:
        print(make_row(cells, mark))
    print(make_line())

    total = len(test_cases)
    color = GREEN if pass_count == total else RED
    print(f"{color}PASS: {pass_count}/{total}{RESET}")
    return pass_count == total


def run_tests(solutions, test_cases):
    # solutions를 [(라벨, 함수), ...] 형태로 정규화한다.
    if callable(solutions):                       # 함수 하나
        funcs = [(solutions.__name__, solutions)]
    elif isinstance(solutions, dict):             # {라벨: 함수}
        funcs = list(solutions.items())
    else:                                         # [함수, 함수, ...]
        funcs = [(f.__name__, f) for f in solutions]

    # 함수별로 독립된 표를 출력하고, 표 사이는 빈 줄 3칸으로 띄운다.
    all_pass = True
    for idx, (label, fn) in enumerate(funcs):
        if idx > 0:
            print(GAP, end="")
        all_pass &= _print_one(label, fn, test_cases)
    return all_pass