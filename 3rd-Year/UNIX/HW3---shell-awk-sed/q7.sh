#!/usr/bin/env bash

# Program which will recursively traverse the provided directory and print into a given file.

shopt -s nullglob

recursive_ls() {
	local dir="$1"
	local indent="${2:-}"
	if [[ -d $dir ]]; then
		for file in "$dir"/*; do
			echo "$indent$(basename "$file")$([[ -d $file ]] && echo "/")"
			recursive_ls "$file" "$indent""    "
		done
	fi
}

recursive_ls "${1:-.}" >"${2:-/dev/stdout}"
