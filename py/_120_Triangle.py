"""
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
"""
from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        minPaths = triangle[-1]
        for level in range(len(triangle) - 2, -1, -1):
            for i in range(len(triangle[level])):
                minPaths[i] = min(minPaths[i], minPaths[i + 1]) + triangle[level][i]
        return minPaths[0]
