# Problem

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v

# Tags

#medium #dp

# Solution

## define state:

d[i][j][k]: profit on day i with j transactions and state k
k=0: all transactions are closed
k=1: there is a buy transaction
k=2: there is a sell transaction

## scenario 1

Nothing happens on day i

    d[i][j][0]=d[i-1][j][0]
    d[i][j][1]=d[i-1][j][1]
    d[i][j][2]=d[i-1][j][2]

## scenario 2

Buy on day i, and it's a new transaction

    d[i][j][1]=d[i-1][j-1][0]-prices[i]

Buy on day i, and it's a close transaction of last short transaction

    d[i][j][0]=d[i-1][j][2]-prices[i]

## scenario 3

Short on day i, and it's a new transaction

    d[i][j][2]=d[i-1][j-1][0]+prices[i]

Short on day i, and it's a close transaction of last buy transaction

    d[i][j][0]=d[i-1][j][1]+prices[i]

## state transition:

d[i][j][0]=max(d[i-1][j][0], d[i-1][j][2]-prices[i], d[i-1][j][1]+prices)
d[i][j][1]=max(d[i][j][1], d[i-1][j-1][0]-prices[i])
d[i][j][2]=max(d[i][j][2], d[i-1][j-1][0]+prices[i])
