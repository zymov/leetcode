class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not len(matrix):
            return
        res = []
        left, right, top, bottom, x, y = 0, len(matrix[0]) - 1, 0, len(matrix) - 1, 0, 0
        
        while left <= right and top <= bottom:
            res.append(matrix[y][x])
            if y == top and x < right:
                x += 1
            elif x == right and y < bottom:
                y += 1
            elif y == bottom and y != top and x > left:
                x -= 1
            elif x == left and x != right and y > top:
                if y == top + 1:
                    left += 1
                    top += 1
                    right -= 1
                    bottom -= 1
                    x = left
                    y = top
                else:
                    y -= 1
            else:
                break
        return res
