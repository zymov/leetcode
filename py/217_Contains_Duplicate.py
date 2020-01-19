from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        m = {}
        for i in nums:
            if m.get(i):
                return True
            m[i] = True
        return False

    def containsDuplicate2(self, nums: List[int]) -> bool:
        if len(nums) < 2:
            return False
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return True
        return False
