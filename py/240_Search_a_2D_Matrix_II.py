from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        y, cols, x = len(matrix) - 1, len(matrix[0]), 0
        while y >= 0 and x < cols:
            if matrix[y][x] == target:
                return True
            elif matrix[y][x] > target:
                y -= 1
            else:
                x += 1
        return False
