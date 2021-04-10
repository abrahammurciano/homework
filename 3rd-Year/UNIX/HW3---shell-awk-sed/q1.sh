#!/usr/bin/env bash

# print the names of everyone currently on the system

who | awk '{print($1)}' | uniq