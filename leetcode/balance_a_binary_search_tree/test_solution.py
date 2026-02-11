import pytest


from cp.dsa.leetcode import TreeNode
from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a, expected",
        [
            (
                TreeNode.from_list([1, None, 2, None, 3, None, 4, None, None]),
                TreeNode.from_list([2, 1, 3, None, None, None, 4]),
            ),
            (TreeNode.from_list([2, 1, 3]), TreeNode.from_list([2, 1, 3])),
        ],
    )
    def test_func(self, a, expected):
        result = self.solution.balanceBST(a)
        assert result == expected
