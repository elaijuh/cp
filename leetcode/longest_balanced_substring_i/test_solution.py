import pytest


from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a, expected",
        [
            ("abbac", 4),
            ("zzabccy", 4),
            ("aba", 2),
        ],
    )
    def test_func(self, a, expected):
        result = self.solution.longestBalanced(a)
        assert result == expected
