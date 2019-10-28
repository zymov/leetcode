from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        path = [grid[0][0]]
        rows, columns = len(grid), len(grid[0])
        for i in range(1, columns):
            path.append(path[i - 1] + grid[0][i])
        for i in range(1, rows):
            path[0] = path[0] + grid[i][0]
            for j in range(1, columns):
                path[j] = grid[i][j] + min(path[j], path[j - 1])
        return path[columns - 1]
