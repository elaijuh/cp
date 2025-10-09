#! /usr/bin/env bash

num=$(echo ${1} | cut -d'_' -f1)
name=$(echo ${1} | cut -d'_' -f2)
link=https://leetcode.com/problems/$name

wd=$(dirname $(realpath $0))
mkdir -p $wd/${1}

cat >$wd/${1}/problem.txt <<-EOF
	$link
EOF

cat >$wd/${1}/s1.cpp <<-EOF
	#include <bits/stdc++.h>
	using namespace std;
EOF

# cat >$wd/${1}/s1.c <<-EOF
# 	#include <stdio.h>
# EOF
