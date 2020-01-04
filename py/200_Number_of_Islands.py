from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        if rows == 0:
            return 0
        cols = len(grid[0])
        count = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    self.dfsMark(grid, i, j)
                    count += 1
        return count

    def dfsMark(self, grid: List[List[str]], row: int, col: int):
        if row < 0 or col < 0 or row > len(grid) - 1 or col > len(grid[0]) - 1 or grid[row][col] == '0':
            return
        grid[row][col] = '0'
        self.dfsMark(grid, row - 1, col)
        self.dfsMark(grid, row + 1, col)
        self.dfsMark(grid, row, col - 1)
        self.dfsMark(grid, row, col + 1)
