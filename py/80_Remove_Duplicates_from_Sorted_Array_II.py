from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return len(nums)
        insertPos = 1
        for i in range(1, len(nums) - 1):
            if nums[i - 1] != nums[i + 1]:
                nums[insertPos] = nums[i]
                insertPos += 1
        nums[insertPos] = nums[-1]
        return insertPos + 1
