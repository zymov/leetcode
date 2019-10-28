from typing import List

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 for i in range(n)] for j in range(n)]
        left, right, top, bottom, x, y, i = 0, n - 1, 0, n - 1, 0, 0, 1
        while left <= right and top <= bottom:
            res[y][x] = i
            i += 1
            if y == top and x < right:
                x += 1
            elif x == right and y < bottom:
                y += 1
            elif y == bottom and y != top and x > left:
                x -= 1
            elif x == left and x != right and y > top:
                if y == top + 1:
                    left += 1
                    right -= 1
                    top += 1
                    bottom -= 1
                    x = left
                    y = top
                else:
                    y -= 1
            else:
                break
        return res
