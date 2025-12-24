# Problem: delete-columns-to-make-sorted-iii

https://leetcode.com/problems/delete-columns-to-make-sorted-iii

# Tags

#hard #dp #string

# Solution

state: let dp[i] be the number of colums to keep

transition: dp[i]=max(dp[i], dp[i+1])

answer is the total column - max(dp)
