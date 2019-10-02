"""
Given an array nums of n integers and an integer target, 
are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
"""
from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        # [-2, -1, 0, 0, 1, 2]
        res = []
        nums.sort()
        l = len(nums)
        i = 0
        while i < l:
            j = i + 1
            while j < l:
                remain = target - nums[i] - nums[j]
                h, k = j + 1, l - 1
                while h < k:
                    if remain - nums[h] > nums[k]:
                        h += 1
                    elif remain - nums[h] < nums[k]:
                        k -= 1
                    else:
                        res.append((nums[i], nums[j], nums[h], nums[k]))
                        while h < k and nums[h + 1] == nums[h]:
                            h += 1
                        while h < k and nums[k - 1] == nums[k]:
                            k -= 1
                        h += 1
                        k -= 1
                while j < l - 1 and nums[j + 1] == nums[j]:
                    j += 1
                j += 1
            while i < l - 1 and nums[i + 1] == nums[i]:
                i += 1
            i += 1
        return res
