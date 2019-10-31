from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]:
            return False
        rows, cols = len(matrix), len(matrix[0])
        low, high = 0, rows * cols - 1
        while low < high:
            mid = low + (high - low) // 2
            if matrix[mid // cols][mid % cols] < target:
                low = mid + 1
            elif matrix[mid // cols][mid % cols] > target:
                high = mid - 1
            else:
                return True
        return matrix[low // cols][low % cols] == target

        