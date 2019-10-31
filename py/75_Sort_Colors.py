from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, pos0, pos2 = 0, 0, len(nums) - 1
        while i < len(nums):
            if nums[i] == 2 and i < pos2:
                nums[i], nums[pos2] = nums[pos2], nums[i]
                pos2 -= 1
                i -= 1
            elif nums[i] == 0:
                nums[i], nums[pos0] = nums[pos0], nums[i]
                pos0 += 1
            i += 1

sol = Solution()
sol.sortColors([1, 0, 0,2,1, 0, 2])