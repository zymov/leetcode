/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int row = obstacleGrid.size(); 
            int column = obstacleGrid[0].size();
            vector<vector<int>> dp(row + 1, vector<int>(column + 1, 0));
            dp[1][0] = 1;
            for(int i = 1; i <= row; i++) {
                for(int j = 1; j <= column; j++) {
                    if(obstacleGrid[i - 1][j - 1] == 0) {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
            return dp[row][column];
        }

        int uniquePathsWithObstacles_LessSpace(vector<vector<int>>& obstacleGrid) {
            int row = obstacleGrid.size();
            int col = obstacleGrid[0].size();
            vector<int> dp(col, 0);
            dp[0] = 1;

            for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                    if(obstacleGrid[i][j]) {
                        dp[j] = 0;
                    } else if(j > 0) {
                        dp[j] += dp[j - 1];
                    }
                }
            }

            return dp[col - 1];
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/