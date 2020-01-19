from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        m = {}
        for i in nums:
            if m.get(i):
                return True
            m[i] = True
        return False
