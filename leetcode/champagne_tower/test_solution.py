import pytest


# from cp.dsa.leetcode import TreeNode
from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a,b,c,expected",
        [
            (1, 1, 1, 0.00000),
            (2, 1, 1, 0.50000),
            (100000009, 33, 17, 1.00000),
        ],
    )
    def test_func(self, a, b, c, expected):
        result = self.solution.champagneTower(a, b, c)
        assert result == expected
