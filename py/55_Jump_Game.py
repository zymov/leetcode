class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxPos = 0
        for i in range(len(nums)):
            if maxPos < i:
                return False
            if maxPos < nums[i] + i:
                maxPos = nums[i] + i
        return True
