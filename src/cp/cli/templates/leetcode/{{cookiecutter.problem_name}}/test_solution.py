import pytest


# from cp.dsa.leetcode import TreeNode
from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a, expected",
        [
            (None, True),
        ],
    )
    def test_func(self, a, expected):
        result = self.solution.func(a)
        assert result == expected
