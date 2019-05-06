/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

Explanation:
Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int row = board.size();
            if(row == 0) return;
            int col = board[0].size();
            // check four borders
            for(int i = 0; i < row; i++) {
                mark(board, i, 0, row, col);
                if(col > 1) mark(board, i, col - 1, row, col);
            }
            for(int i = 0; i < col; i++) {
                mark(board, 0, i, row, col);
                if(row > 1) mark(board, row - 1, i, row, col);
            }
            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    if(board[i][j] == 1) board[i][j] = 'O';
                    else if(board[i][j] == 'O') board[i][j] = 'X';
                }
            }
        }

        void mark(vector<vector<char>>& board, int y, int x, int row, int col) {
            if(board[y][x] == 'O') {
                board[y][x] = 1;
                if(x + 1 < col) {
                    mark(board, y, x + 1, row, col);
                }
                if(y + 1 < row) {
                    mark(board, y + 1, x, row, col);
                }
                if(x > 1) {
                    mark(board, y, x - 1, row, col);
                }
                if(y > 1) {
                    mark(board, y - 1, x, row, col);
                }
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/