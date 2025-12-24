#!/usr/bin/env bash

files=$(find . -name "problem.md")

for f in ${files[@]}; do
	problem=$(echo $f | cut -d'/' -f2)
	sed -i "1c# Problem: $problem" $f
done
