# Problem: max-dot-product-of-two-subsequences

Contest: https://leetcode.com/contest/weekly-contest-190/\
Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences\
Points: 6

# Tags

#hard #dp

# Similar

# Solution

`dp[i][j]` = max dot product of 2 subsequences start from nums1[i] and nums2[j]. To calculate `dp[i][j` from bottom up, we have 4 options everytime pick the max of these 4 optioons:

- `nums1[i]*nums2[j] + dp[i+1][j+1]`. Pick nums1[i]*nums2[j] which makes the dot product bigger
- `dp[i+1][j+1]`. Don't pick nums1[i]*nums2[j] as it makes dot product smaller
- `dp[i+1][j]`. Don't pick nums1[i] but picks nums2[j]
- `dp[i][j+1]`. Don't pick nums2[j] but picks nums1[i]

Finally `dp[0][0]` will the result we want.
