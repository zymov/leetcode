from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            tmp = numbers[l] + numbers[r]
            if tmp == target:
                return [l, r]
            elif tmp < target:
                l = l + 1
            else:
                r = r - 1
