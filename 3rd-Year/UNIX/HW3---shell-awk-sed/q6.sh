#!/usr/bin/env bash

# Program which will go through all the files in the current directory and append to them the words "I WAS HERE."

for file in *; do
    echo "I WAS HERE" >> "$file"
done