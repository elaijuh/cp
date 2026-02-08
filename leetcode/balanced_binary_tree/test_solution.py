import pytest


from cp.dsa.leetcode import TreeNode
from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a, expected",
        [
            ([3, 9, 20, None, None, 15, 7], True),
            ([1, 2, 2, 3, 3, None, None, 4, 4], False),
            ([], True),
        ],
    )
    def test_func(self, a: list, expected: bool):
        root = TreeNode.from_list(a)

        result = self.solution.isBalanced(root)
        assert result == expected
