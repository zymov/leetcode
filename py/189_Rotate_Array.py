from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k, n = k % len(nums), len(nums) - 1
        self.reverse(nums, 0, n - k)
        self.reverse(nums, n - k + 1, n)
        self.reverse(nums, 0, n)

    def reverse(self, nums: List[int], l: int, r: int):
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
