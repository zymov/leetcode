from typing import List


class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        stack, start, end = [], nums[0], nums[0]
        for i in range(1, len(nums)):
            if nums[i] == end + 1:
                end = nums[i]
            else:
                if start == end:
                    stack.append(self.printRange(start, end))
                else:
                    stack.append(self.printRange(start, end))
                start = nums[i]
                end = nums[i]
        stack.append(self.printRange(start, end))
        return stack

    def printRange(self, l, r):
        if l == r:
            return str(l)
        else:
            return str(l) + "->" + str(r)
