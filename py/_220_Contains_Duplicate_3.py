"""
Given an array of integers,
find out whether there are two distinct indices i and j in the array
such that the absolute difference between nums[i] and nums[j] is at most t
and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
"""

from typing import List

class Solution:

    """
    The idea is like the bucket sort algorithm.
    Suppose we have consecutive buckets covering the range of nums
    with each bucket a width of (t+1).
    If there are two item with difference <= t, one of the two will happen:
        (1) the two in the same bucket
        (2) the two in neighbor buckets
    """

    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0: return False
        N = len(nums)
        S = {}
        interval = t + 1
        for i in range(N):
            bucketIndex = nums[i] // interval
            if bucketIndex in S:
                return True
            if bucketIndex - 1 in S and abs(nums[i] - S[bucketIndex - 1]) < interval:
                return True
            if bucketIndex + 1 in S and abs(nums[i] - S[bucketIndex + 1]) < interval:
                return True
            S[bucketIndex] = nums[i]
            if i >= k:
                del S[nums[i - k] // interval]
        return False
