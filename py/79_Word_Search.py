class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board:
            return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.backtracking(board, word, j, i):
                    return True
        return False
        
    def backtracking(self, board: List[List[str]], word: str, x: int, y: int) -> bool:
        if board[y][x] == word[0]:
            if not word[1:]:
                return True
            board[y][x] = ''
            if x < len(board[y]) - 1 and self.backtracking(board, word[1:], x + 1, y):
                return True
            if x > 0 and self.backtracking(board, word[1:], x - 1, y):
                return True
            if y > 0 and self.backtracking(board, word[1:], x, y - 1):
                return True
            if y < len(board) - 1 and self.backtracking(board, word[1:], x, y + 1):
                return True
            board[y][x] = word[0]
            return False
        else:
            return False
