#!/usr/bin/env bash

# Shell script to run all executable files in a given directory.

for file in "$1"/*; do
    if [[ -x "$file" && -f "$file" ]]; then
        $file
    fi
done