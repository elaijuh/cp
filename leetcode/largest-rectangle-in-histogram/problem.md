# Problem: largest-rectangle-in-histogram

https://leetcode.com/problems/largest-rectangle-in-histogram

# Tags

#hard #monotonic_stack

# Solution

- Use decreasing monotonic stack to calcular NSL(nearest smaller element to the left) and NSR (nearest smaller element to the right)
- For each bar, the max area is heights[i]*(nsr[i]-nsl[i]-1)
