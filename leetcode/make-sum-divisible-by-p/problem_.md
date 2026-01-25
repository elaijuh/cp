# Problem: make-sum-divisible-by-p

Contest: https://leetcode.com/contest/biweekly-contest-35/\
Link: https://leetcode.com/problems/make-sum-divisible-by-p
Points: 5

# Tags

#medium #prefix_sum #math

# Similar

- https://leetcode.com/problems/subarray-sums-divisible-by-k

# Solution

sum[i..j] = sum[j]-sum[i-1]
