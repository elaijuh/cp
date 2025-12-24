# Problem: number-of-smooth-descent-periods-of-a-stock

https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock

# Tags

#medium #dp #stack

# Solution

## S1: use stack

## S2: use dp

dp[i]: number of periods end on day i, dp[0]=1.\
if prices[i-1]-1==prices[i], dp[i]=dp[i-1]+1. else dp[i]=1\
sum of dp[i] is the answer.
