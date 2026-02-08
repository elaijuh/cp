from typing import Optional
from cp.dsa.leetcode import TreeNode


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        ans = True

        def dfs(node):
            nonlocal ans
            if not node or not ans:
                return 0
            l = dfs(node.left)
            r = dfs(node.right)
            if abs(l - r) > 1:
                ans = False
            return max(l, r) + 1

        dfs(root)
        return ans
