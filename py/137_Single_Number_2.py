from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        low, high = 0, 0
        for i in range(len(nums)):
            low = (low ^ nums[i]) & ~high;
            high = (high ^ nums[i]) & ~low;
        return low
