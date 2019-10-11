"""
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


[4,5,6,7,8,1,2,3]
8
"""
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r, mid = 0, len(nums) - 1, None
        if r == -1:
            return -1
        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        minIndex = l
        front, end = 0, len(nums) - 1
        if nums[minIndex] == target:
            return minIndex
        elif target > nums[end]:
            end = minIndex - 1
        else:
            front = minIndex
        while front <= end:
            mid = front + (end - front) // 2
            if nums[mid] < target:
                front = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                return mid
        return -1
            