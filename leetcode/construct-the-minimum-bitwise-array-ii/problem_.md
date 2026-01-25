# Problem: construct-the-minimum-bitwise-array-ii

Contest: https://leetcode.com/contest/biweekly-contest-141/\
Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii
Points: 5

# Tags

#medium #math #bit

# Similar

- https://leetcode.com/problems/construct-the-minimum-bitwise-array-i

# Solution

Let say a | a+1 = b, b can be calculated as scanning a from least significant bit and find first 0 and flip it to 1. Thus if we know b, we can find a by locating the first 0 in b and set the next 1 after it to 0
