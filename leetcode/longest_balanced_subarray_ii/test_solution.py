import pytest


# from cp.dsa.leetcode import TreeNode
from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a, expected",
        [
            ([2, 5, 4, 3], 4),
            ([3, 2, 2, 5, 4], 5),
            ([1, 2, 3, 2], 3),
        ],
    )
    def test_func(self, a, expected):
        result = self.solution.longestBalanced(a)
        assert result == expected
