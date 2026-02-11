import pytest

from .solution import Solution


class TestFunc:
    def setup_method(self):
        self.solution = Solution()

    @pytest.mark.parametrize(
        "a, b,expected",
        [
            ([2, 3, 1, 2, 4, 3], 7, 2),
            ([1, 4, 4], 4, 1),
            ([1, 1, 1, 1, 1, 1, 1, 1], 11, 0),
        ],
    )
    def test_func(self, a, b, expected):
        result = self.solution.minSubArrayLen(b, a)
        assert result == expected
