#! /usr/bin/env bash

set -e

cid=$(echo ${1} | cut -d'_' -f1)
cname=$(curl -s https://codeforces.com/api/contest.list | jq -r --arg cid "$cid" '.result[] | select(.id == ($cid|tonumber)) | .name')
pindex=$(echo ${1} | cut -d'.' -f1 | cut -d'_' -f2)
plink=https://codeforces.com/contest/$cid/problem/${pindex^^}
problems=$(curl -s https://codeforces.com/api/problemset.problems)
pname=$(echo $problems | jq -r --arg cid "$cid" --arg pindex ${pindex^^} '.result.problems[] | select(.contestId == ($cid|tonumber)) | select(.index == $pindex)| .name')
ptags=($(echo $problems | jq -r --arg cid "$cid" --arg pindex ${pindex^^} '.result.problems[] | select(.contestId == ($cid|tonumber)) | select(.index == $pindex)| .tags[]'))
tags=""
for t in ${ptags[@]}; do tags+="#$t "; done

ext=$(echo ${1} | cut -d'.' -f2)
if [[ "$ext" == "cpp" ]]; then
  cat >${1} <<EOF
// $plink
// $cname, ${pindex^^}.$pname
// $tags

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    return 0;
}
EOF
elif [[ "$ext" == "c" ]]; then
  cat >${1} <<EOF
// $plink
// $cname, ${pindex^^}.$pname
// $tags

#include <stdio.h>

int main()
{
    return 0;
}
EOF
fi
