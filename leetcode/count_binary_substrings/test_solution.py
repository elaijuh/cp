import pytest


# from cp.dsa.leetcode import TreeNode
from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a, expected",
        [
            ("00110011", 6),
            ("10101", 4),
        ],
    )
    def test_func(self, a, expected):
        result = self.solution.countBinarySubstrings(a)
        assert result == expected
