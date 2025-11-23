# Problem

https://leetcode.com/problems/find-maximum-balanced-xor-subarray-length

# Tags

#medium #math #xor

# Solution

1. define mp[xr][k]=i: xr = xor from nums[0] to nums[i], k = number of odds.
2. loop to j, if mp[xr][k] exists that means subarray i+1..j xor to zero and numer of odds and evens are equal.
3. j-i is the length we want.
