#!/usr/bin/env python3
import subprocess
import sys
from pathlib import Path

def staged_files():
    result = subprocess.run(
        ["git", "diff", "--cached", "--name-only", "--diff-filter=ACM"],
        capture_output=True,
        text=True,
        check=True,
    )
    return [Path(f) for f in result.stdout.splitlines()]

def is_text_file(path: Path) -> bool:
    try:
        with path.open("rb") as f:
            chunk = f.read(1024)
        b"\0" not in chunk
    except Exception:
        return False
    return True

def has_utf8_bom(path: Path) -> bool:
    with path.open("rb") as f:
        return f.read(3) == b"\xef\xbb\xbf"

def is_utf8_or_ascii(path: Path) -> bool:
    try:
        path.read_text(encoding="utf-8")
        return True
    except UnicodeDecodeError:
        return False

def main():
    failed = False

    for file in staged_files():
        if not file.is_file():
            continue

        if not is_text_file(file):
            continue

        if has_utf8_bom(file):
            print(f"Error: {file} contains UTF-8 BOM", file=sys.stderr)
            failed = True
            continue

        if not is_utf8_or_ascii(file):
            print(f"Error: {file} is not UTF-8 / ASCII encoded", file=sys.stderr)
            failed = True

    if failed:
        sys.exit(1)

if __name__ == "__main__":
    main()
