# Problem: minimum-cost-path-with-teleportations

Contest: https://leetcode.com/contest/biweekly-contest-163/\
Link: https://leetcode.com/problems/minimum-cost-path-with-teleportations
Points: 6

# Tags

#hard #dp #matrix

# Similar

# Solution

cost[i][j]: minimum cost from (i,j) to (m-1,n-1)

Init state:

    cost[m-1][n-1]=0

Transition:

    Teleport: (i,j)->(x,y)
    cost[i][j] = min(cost[x][y]) for (x,y) in points if grid[x][y]<=grid[i][j]

    Move (i,j)->(i+1,j) or (i,j)->(i,j+1):
    cost[i][j]=min(
    	cost[i][j],
    	cost[i+1][j]+grid[i+1][j],
    	cost[i][j+1]+grid[i][j+1]
    )
