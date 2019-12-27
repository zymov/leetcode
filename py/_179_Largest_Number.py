from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        self.quickSort(nums, 0, len(nums) - 1)
        return str(int(''.join(map(str, nums))))

    def compare(self, x: int, y: int) -> bool:
        return str(x) + str(y) > str(y) + str(x)

    def quickSort(self, nums: List[int], l: int, r: int) -> str:
        if l >= r:
            return
        p = self.partition(nums, l, r)
        self.quickSort(nums, l, p - 1)
        self.quickSort(nums, p + 1, r)

    def partition(self, nums: List[int], l: int, r: int):
        low = l
        while l < r:
            if self.compare(nums[l], nums[r]):
                # partition number is nums[r], move all the larger numbers to the left of partition number
                nums[l], nums[low] = nums[low], nums[l]
                low += 1
            l += 1
        nums[low], nums[r] = nums[r], nums[low] # find the right place of partition number
        return low


    def mergeSort(self, nums: List[int], l: int, r: int) -> str:
        if l > r:
            return
        elif l == r:
            return [nums[l]]
        mid = l + (r - l) // 2
        left = self.mergeSort(nums, l, mid)
        right = self.mergeSort(nums, mid + 1, r)
        return self.merge(left, right)

    def merge(self, l1, l2) -> List[int]:
        res, i, j = [], 0, 0
        while i < len(l1) and j < len(l2):
            if self.compare(l1[i], l2[j]):
                res.append(l1[i])
                i += 1
            else:
                res.append(l2[j])
                j += 1
        res.extend(l1[i:] or l2[j:])
        return res

    # def bubbleSort(self, nums: List[int]) -> str:

    # def selectionSort(self, nums: List[int]) -> str:

    # def insertionSort(self, nums: List[int]) -> str:

