from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if not len(obstacleGrid) or not len(obstacleGrid[0]):
            return 0
        path, rows, columns = [0], len(obstacleGrid), len(obstacleGrid[0])
        for i in range(columns):
            if obstacleGrid[0][i]:
                for j in range(i, columns):
                    path.append(0)
                break
            path.append(1)
        for i in range(1, rows):
            for j in range(columns):
                if obstacleGrid[i][j]:
                    path[j + 1] = 0
                else:
                    path[j + 1] = path[j] + path[j + 1]
        return path[columns]
        