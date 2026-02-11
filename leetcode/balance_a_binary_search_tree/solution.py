from typing import Optional
from cp.dsa.leetcode import TreeNode


class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        tree = []

        def dfs(root):
            nonlocal tree
            if not root:
                return None
            dfs(root.left)
            tree.append(root.val)
            dfs(root.right)

        def build_tree(arr, start, end):
            if start > end:
                return None
            m = start + (end - start) // 2
            root = TreeNode(arr[m])
            root.left = build_tree(arr, start, m - 1)
            root.right = build_tree(arr, m + 1, end)
            return root

        dfs(root)
        ans = build_tree(tree, 0, len(tree) - 1)
        return ans
