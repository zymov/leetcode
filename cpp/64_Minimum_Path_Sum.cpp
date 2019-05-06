/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int row = grid.size(),
                col = grid[0].size();
            vector<vector<int>> path(row, vector<int>(col, grid[0][0]));
            for(int i = 1; i < row; i++) {
                path[i][0] = path[i - 1][0] + grid[i][0];
            }
            for(int j = 1; j < col; j++) {
                path[0][j] = path[0][j - 1] + grid[0][j];
            }
            for(int i = 1; i < row; i++) {
                for(int j = 1; j < col; j++) {
                    path[i][j] = min(path[i][j - 1], path[i - 1][j]) + grid[i][j];
                }
            }
            return path[row - 1][col - 1];
        }

        int minPathSum_LessSpace(vector<vector<int>>& grid, int row, int col) {
            int row = grid.size(),
                col = grid[0].size();
            vector<int> path(col, grid[0][0]);
            for(int i = 1; i < col; i++) {
                path[i] = path[i - 1] + grid[0][i];
            }
            for(int i = 1; i < row; i++) {
                path[0] += grid[i][0];
                for(int j = 1; j < col; j++) {
                    path[j] = min(path[j - 1], path[j]) + grid[i][j];
                }
            }
            return path[col - 1];
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/