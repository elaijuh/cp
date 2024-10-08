#! /usr/bin/env bash

ct=$(echo ${1} | cut -d'_' -f1)
name=$(echo ${1} | cut -d'.' -f1)
ext=$(echo ${1} | cut -d'.' -f2)
link=https://atcoder.jp/contests/$ct/tasks/$name

if [[ "$ext" == "cpp" ]]; then
  cat >${1} <<EOF
// $link
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  return 0;
}
EOF
elif [[ "$ext" == "c" ]]; then
  cat >${1} <<EOF
// $link
#include "stdio.h"

int main()
{
  return 0;
}
EOF
fi
