from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        low, high = 0, len(nums) - 1
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return True
            if nums[low] == nums[mid] and nums[mid] == nums[high]:
                low += 1
                high -= 1
            elif nums[low] <= nums[mid]:
                if target < nums[mid] and nums[low] <= target:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid] < target and target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
        return False
