"""
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3

Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28
"""

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        pathTo = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                pathTo[i][j] = pathTo[i - 1][j] + pathTo[i][j - 1]
        return pathTo[-1][-1]
    
    def uniquePaths_lessMemory(self, m: int, n: int) -> int:
        pathTo = [1] * m
        for _ in range(1, n):
            for i in range(1, m):
                pathTo[i] += pathTo[i - 1]
        return pathTo[-1]
