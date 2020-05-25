#!/bin/bash
if [ -z "$1" ]
  then
    echo "Problem Title not provided"
    exit 1
fi
# cd leetcode/
folder=$1
mkdir "$folder"
cd "$folder"
cat "../problem.bookmark.js" > README.md
cat "../answer.bookmark.js" > s1.cpp
echo "DONE: "$folder
