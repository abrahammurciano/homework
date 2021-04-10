#!/usr/bin/env bash

# Program which will print the name of, and then delete files containing the words fish, phish, or phych, unless it contains the word fisherman.

ls | grep -v fisherman | grep -E "fish|phish|phych" | xargs -I@ sh -c "echo '@' && rm '@'"