#!/usr/bin/env bash

# Program which will capitalize the first letter of all sentences in all files in the directory txt.

for file in txt/*; do
    replaced=$(< "$file" tr '\n' '\r' | sed -Ee 's/((?:^|[.!?]['")\]’]?\s+)['‘"([]?)([a-z])/\1\U\2/g' | tr '\r' '\n')
    echo "$replaced" > "$file"
done
