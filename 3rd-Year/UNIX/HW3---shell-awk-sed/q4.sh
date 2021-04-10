#!/usr/bin/env bash

# Program which will print to the screen any file starting with the string #include

for file in *; do
    if [ "$(head -c9 "$file")" == "#include" ]; then
        cat "$file"
        echo ""
    fi
done