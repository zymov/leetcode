/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:
11110
11010
11000
00000

Output: 1

Example 2:
Input:
11000
11000
00100
00011

Output: 3
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    private:
        int m, n;
    public:
        int numIslands(vector<vector<char>>& grid) {
            m = grid.size();
            if(m == 0) return 0;
            n = grid[0].size();
            int count = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == '1') {
                        DFSMark(grid, i, j);
                        count++;
                    }
                }
            }
            return count;
        }

        void DFSMark(vector<vector<char>>& grid, int row, int col) {
            if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0') return;
            grid[row][col] = '0';
            DFSMark(grid, row - 1, col);
            DFSMark(grid, row + 1, col);
            DFSMark(grid, row, col - 1);
            DFSMark(grid, row, col + 1);
        }
};

int main() {
    return 0;
}

/*


*/