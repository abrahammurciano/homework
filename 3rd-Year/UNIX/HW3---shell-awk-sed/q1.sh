#!/usr/bin/env bash

# print the names of everyone currently on the system

who | cut -f1 -d' ' | uniq
