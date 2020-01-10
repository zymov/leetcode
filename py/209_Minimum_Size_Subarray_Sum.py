from typing import List

class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        minLen, total, start = len(nums) + 1, 0, 0
        for i in range(len(nums)):
            total += nums[i]
            while total >= s:
                minLen = min(minLen, i - start + 1)
                total -= nums[start]
                start += 1
        return minLen if minLen <= len(nums) else 0
