#! /usr/bin/env bash

ct=$(echo ${1} | cut -d'_' -f1)
name=$(echo ${1} | cut -d'.' -f1)
ext=$(echo ${1} | cut -d'.' -f2)
link=https://atcoder.jp/contests/$ct/tasks/$name

wd=$(dirname $(realpath $0))
mkdir -p $wd/$ct

if [[ "$ext" == "cpp" ]]; then
	cat >$wd/$ct/${name##*_}.cpp <<-EOF
		// $link

		#include <bits/stdc++.h>
		using namespace std;

		int main()
		{
		    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		    return 0;
		}
	EOF
elif [[ "$ext" == "c" ]]; then
	cat >$wd/$ct/${name##*_}.c <<-EOF
		// $link

		#include <stdio.h>

		int main()
		{
		    return 0;
		}
	EOF
fi
