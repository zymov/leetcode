from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        majorA = majorB = None
        countA, countB = 0, 0
        for i in nums:
            if i == majorA:
                countA += 1
            elif i == majorB:
                countB += 1
            elif countA == 0:
                majorA = i
                countA = 1
            elif countB == 0:
                majorB = i
                countB = 1
            else:
                countA -= 1
                countB -= 1

        countA = countB = 0
        for i in nums:
            if i == majorA:
                countA += 1
            elif i == majorB:
                countB += 1
        res = []
        if countA > len(nums) // 3:
            res.append(majorA)
        if countB > len(nums) // 3:
            res.append(majorB)
        return res
