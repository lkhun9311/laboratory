#!/usr/bin/env bash
# 사용법: ./run.sh LV1/'!53_완주하지_못한_선수.cpp'
#         ./run.sh LV2/'!47_....cpp'
# 컴파일 후 바로 실행한다. 전부 통과하면 종료 코드 0.
set -euo pipefail

if [ $# -lt 1 ]; then
  echo "사용법: $0 <cpp 파일>" >&2
  exit 2
fi

src="$1"; shift
# /tmp 는 메모리(tmpfs)라서, 컴파일한 바이너리를 담은 임시 디렉터리를 끝날 때 지운다.
# 채점이 실패해도 지워지고, 종료 코드는 채점 결과 그대로 남는다.
dir="$(mktemp -d)"
trap 'rm -rf "$dir"' EXIT
out="$dir/a"

g++ -std=c++20 -O2 -Wall -Wextra -Wno-unused-parameter "$src" -o "$out" "$@"
"$out"
