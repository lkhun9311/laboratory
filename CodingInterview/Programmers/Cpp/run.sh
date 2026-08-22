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
out="$(mktemp -d)/a"

g++ -std=c++20 -O2 -Wall -Wextra -Wno-unused-parameter "$src" -o "$out" "$@"
"$out"
