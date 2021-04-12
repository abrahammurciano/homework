#!/usr/bin/env bash

# Implementation of wc supporting the flags -l -w -c and any number of files

# read options
while getopts 'lwc' flag; do
	case "$flag" in
	l) lines="true" ;;
	w) words="true" ;;
	c) chars="true" ;;
	*)
		echo "Invalid option $flag"
		exit 1
		;;
	esac
done

# if no options are specified, use all
if [[ -z "$lines" && -z "$words" && -z "$chars" ]]; then
	lines="true"
	words="true"
	chars="true"
fi

shift $((OPTIND - 1)) # discard flags

for file in "$@"; do
	if [[ "$lines" == "true" ]]; then
		n_lines=$(awk '{++lines}END{print lines}' "$file")"$(printf '\t')"
	fi
	if [[ "$words" == "true" ]]; then
		n_words=$(awk 'BEGIN{FS="[^a-zA-Z0-9]+"}{for(i=0; i<NF; ++i) if (length($i) > 0) ++words}END{print words}' "$file")"$(printf '\t')"
	fi
	if [[ "$chars" == "true" ]]; then
		n_chars=$(awk '{chars+=length($0)+1}END{print chars}' "$file")
		if [[ $(tail -n 1 "$file") != "" ]]; then # if doesn't end in newline, awk command gives extra character
			n_chars=$((n_chars - 1))
		fi
		n_chars="$n_chars$(printf '\t')"
	fi
	echo "$n_lines$n_words$n_chars$file"
done
