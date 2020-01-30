from typing import List


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n, sz = len(matrix), len(matrix[0]), 0
        dp = [[0 for j in range(n)] for i in range(m)]

        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0 or matrix[i][j] == '0':
                    dp[i][j] = 0 if matrix[i][j] == '0' else 1
                else:
                    dp[i][j] = min(
                        dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1
                sz = max(dp[i][j], sz)

        return sz**2
