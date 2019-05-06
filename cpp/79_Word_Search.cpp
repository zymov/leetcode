/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int row = board.size(), col = board[0].size();
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    if(backtracking(board, word, row, col, 0, i, j)) return true;
                }
            }
            return false;
        }

        bool backtracking(vector<vector<char>>& board, string& word, int row, int col, int pos, int x, int y) {
            if(word[pos] != board[x][y]) return false;
            if(pos == word.size() - 1) return true;
            bool res = false;
            char bc = board[x][y];
            board[x][y] = '*';
            if(x > 0) res = backtracking(board, word, row, col, pos + 1, x - 1, y);
            if(!res && x < row - 1) res = backtracking(board, word, row, col, pos + 1, x + 1, y);
            if(!res && y > 0) res = backtracking(board, word, row, col, pos + 1, x, y - 1);
            if(!res && y < col - 1) res = backtracking(board, word, row, col, pos + 1, x, y + 1);
            board[x][y] = bc;
            return res;
        }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string w = "ABCCED";
    cout << sol.exist(board, w) << endl;
    return 0;
}

/*


*/