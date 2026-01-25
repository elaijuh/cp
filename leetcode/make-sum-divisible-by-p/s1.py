from typing import List


class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        r = sum(nums) % p
        if not r:
            return 0
        n = len(nums)
        # sum[i..j] is represented as prefix_sum[j]-prefix_sum[i-1]
        # thus sum[i..j]%p = r = (prefix_sum[j]-prefix_sum[i-1])%p
        # prefix_sum[i-1]%p = (prefix_sum[j]-r)%p
        mp = {0: -1}
        ans = n
        prefix = 0
        for i in range(n):
            prefix = (prefix + nums[i]) % p
            expected = (prefix - r + p) % p
            ans = min(ans, i - mp[expected] if expected in mp else ans)
            mp[prefix] = i

        return -1 if ans == n else ans
