from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, h = 0, len(nums) - 1
        while l < h:
            m1 = l + (h - l) // 2
            m2 = m1 + 1
            if nums[m1] < nums[m2]:
                l = m2
            else:
                h = m1
        return l
