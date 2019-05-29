"""
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
"""
from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        l = 0
        r = len(nums) - 1
        while True:
            p = self.partition(nums, l, r)
            if p == k - 1:
                return nums[p]
            elif p < k - 1:
                l = p + 1
            else:
                r = p - 1

    def partition(self, nums: List[int], left: int, right: int) -> int:
        pivot = nums[left]
        l = left + 1
        r = right
        while l <= r:
            if pivot > nums[l] and pivot < nums[r]:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
            if pivot <= nums[l]:
                l += 1
            if pivot >= nums[r]:
                r -= 1
        nums[left], nums[r] = nums[r], nums[left]
        return r

    def heapSort(self, nums: List[int], k: int) -> int:
        nums.append(0)
        N = len(nums) - 1
        nums[N], nums[0] = nums[0], nums[N]
        i = N // 2
        for x in range(i, 0, -1):
            self.sink(x, N, nums)
        while k > 0:
            nums[1], nums[N] = nums[N], nums[1]
            self.sink(1, N - 1, nums)
            N -= 1
            k -= 1
        return nums[N + 1]

    def sink(self, k: int, N: int, nums: List[int]):
        while 2*k <= N:
            j = 2*k
            if j < N and nums[j] < nums[j + 1]:
                j += 1
            if nums[k] > nums[j]:
                break
            nums[k], nums[j] = nums[j], nums[k]
            k = j
