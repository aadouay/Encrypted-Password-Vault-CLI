#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <encrypted_data> <serial_ID>" >&2
  exit 1
fi

make

./dec "$1" "$2"
