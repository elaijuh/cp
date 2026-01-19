# Problem: maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold

Contest: https://leetcode.com/contest/weekly-contest-167/\
Link: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
Points: 5

# Tags

#medium #prefix_sum #bs #matrix

# Similar

# Solution

2D prefix sum formular: `P[i][j]=P[i-1][j]+P[i][j-1]-P[i-1][j-1]+A[i][j]`
