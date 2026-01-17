# Problem: number-of-alternating-xor-partitions

Contest: https://leetcode.com/contest/biweekly-contest-174/\
Link: https://leetcode.com/problems/number-of-alternating-xor-partitions

# Tags

#medium #dp #math

# Similar

# Solution

- xor(i..j) = target1 => xor(xor(0..i-1), xor(0..j)) = target1 => xor(0..i-1) = xor(xor(0..j), target1)
- mp1: number of ways where prefix xor to target1
- mp2: number of ways where prefix xor to target2
