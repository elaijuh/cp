# Problem

https://leetcode.com/problems/remove-duplicate-letters

# Tags

#medium #stack

# Solution

- Maintain a stack for lexical order purpose
- If stack.top() > cur and stack.top() occurs after cur again, then stack.pop() and stack.push(cur)
