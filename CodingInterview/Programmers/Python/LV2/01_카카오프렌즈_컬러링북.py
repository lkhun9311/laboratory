# https://school.programmers.co.kr/learn/courses/30/lessons/1829?language=python3

# Number of times solving questions: 1
# 2026-09-15

import sys, pathlib
sys.path.append(str(pathlib.Path(__file__).resolve().parent.parent))  # test_runner 경로
from test_runner import run_tests

from collections import deque

# 규칙 1. 0 은 색칠되지 않은 칸이다. 영역이 아니다.
# 규칙 2. 상하좌우로 맞닿은 같은 색 칸끼리 한 영역이다. 대각선은 닿은 것이 아니다.
# 규칙 3. 영역의 개수와, 그중 가장 큰 영역의 칸 수를 [개수, 최대크기] 로 돌려준다.
#
# 지금까지의 격자 문제와 다른 점은 "얼마나 멀리 가는지 미리 모른다"는 것이다.
# 14번 공원 산책은 갈 칸 수가 명령에 적혀 있었다. 여기서는 번지는 곳까지 번진다.
# 그래서 "앞으로 가 볼 칸"을 큐에 쌓아 두고 빌 때까지 꺼낸다 — 이것이 BFS다.
#
#   1 1 1 0     (0,0) 에서 시작해 같은 색 1 로만 번진다
#   1 2 2 0
#   1 0 0 1     (0,0) → (0,1) (1,0) → (0,2) (2,0) → ...
#   0 0 0 1     ↓ 큐가 빌 때까지
#   0 0 0 3     → 5칸짜리 영역 하나 완성
#   0 0 0 3
#
# 핵심은 visited 를 "꺼낼 때"가 아니라 "넣을 때" 켜는 것이다.
# 꺼낼 때 켜면 같은 칸이 큐에 여러 번 들어가 개수가 부풀고 큐도 터진다.
#
# 바깥의 이중 루프는 "아직 안 가 본 색칠된 칸"을 찾는 역할만 한다.
# 거기서 bfs 를 한 번 부르면 그 영역 하나가 통째로 visited 처리된다.
# 따라서 bfs 를 부른 횟수 = 영역의 개수다.

# 방향 배열은 함수 밖에 한 번만 둔다. 루프 안에서 만들면 칸마다 새로 만들어진다
DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]


def bfs(m, n, r, c, picture, visited):
    queue = deque()
    count = 0
    color = picture[r][c]  # 시작 칸의 색. 이 색으로만 번진다

    queue.append((r, c))
    visited[r][c] = True   # 넣을 때 켠다

    while queue:
        cur_r, cur_c = queue.popleft()
        count += 1

        for dr, dc in DIRECTIONS:
            nr, nc = cur_r + dr, cur_c + dc

            # 범위 검사가 격자 접근보다 먼저여야 한다.
            # 파이썬은 음수 인덱스가 뒤에서부터 읽히므로 에러 없이 조용히 틀린다
            if 0 <= nr < m and 0 <= nc < n and color == picture[nr][nc] and not visited[nr][nc]:
                queue.append((nr, nc))
                visited[nr][nc] = True

    return count


def solution(m, n, picture):
    # 이 문제는 채점기가 solution 을 한 프로세스에서 여러 번 부른다.
    # 전역 변수를 쓰면 이전 호출의 값이 남아 틀린다. 전부 지역 변수로 둔다
    visited = [[False] * n for _ in range(m)]
    area_arr = []

    for r in range(m):
        for c in range(n):
            # 색칠돼 있고 아직 안 가 본 칸 = 새 영역의 시작점
            if picture[r][c] != 0 and not visited[r][c]:
                area_arr.append(bfs(m, n, r, c, picture, visited))

    # default=0 이 없으면 영역이 하나도 없을 때 ValueError 로 죽는다
    return [len(area_arr), max(area_arr, default=0)]


# ─────────────────────────────────────────────────────────────
# 테스트
# ─────────────────────────────────────────────────────────────
test_cases = [
    ((6, 4, [[1,1,1,0],[1,2,2,0],[1,0,0,1],[0,0,0,1],[0,0,0,3],[0,0,0,3]]), [4, 5]),
    # 경계 ① 전부 0 — 영역이 하나도 없다
    ((2, 2, [[0,0],[0,0]]), [0, 0]),
    # 경계 ② 1x1 한 칸
    ((1, 1, [[5]]), [1, 1]),
    # 경계 ③ 같은 색이지만 대각선으로만 닿음 — 별개 영역이다
    ((2, 2, [[1,0],[0,1]]), [2, 1]),
    # 경계 ④ 전부 같은 색 한 덩어리
    ((3, 3, [[7,7,7],[7,7,7],[7,7,7]]), [1, 9]),
    # 경계 ⑤ 다른 색이 맞닿아 있으면 나뉜다
    ((1, 4, [[1,1,2,2]]), [2, 2]),
]

run_tests(solution, test_cases)
