/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximalSquare(vector<vector<char>>& matrix) {
      if(matrix.empty()) return 0;
      int R = matrix.size(), 
          C = matrix[0].size(),
          sideLen = 0;
      vector<vector<int>> dp(R, vector<int>(C, 0));
      for(int i = 0; i < C; i++) {
        dp[0][i] = matrix[0][i] - '0';
        sideLen = max(sideLen, dp[0][i]);
      }
      for(int i = 1; i < R; i++) {
        dp[i][0] = matrix[i][0] - '0';
        sideLen = max(sideLen, dp[i][0]);
      }
      for(int i = 1; i < R; i++) {
        for(int j = 1; j < C; j++) {
          if(matrix[i][j] == '1') {
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i -1][j - 1]) + 1;
            sideLen = max(sideLen, dp[i][j]);
          }
        }
      }
      return sideLen * sideLen;
    }

    int maximalSquare_LessMemory(vector<vector<char>>& matrix) {
      if(matrix.empty()) return 0;
      int R = matrix.size(), 
          C = matrix[0].size(),
          sideLen = 0,
          temp = 0,
          pre = 0;
      vector<int> dp(R + 1, 0);
      for(int j = 0; j < C; j++) {
        for(int i = 1; i <= R; i++) {
          temp = dp[i];
          if(matrix[i - 1][j] == '1') {
            //            ↓--------------------------------------- value been setted in previous j's (column) loop
            dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
            sideLen = max(sideLen, dp[i]);
          } else {
            dp[i] = 0;
          }
          pre = temp;
        }
      }
      return sideLen * sideLen;
    }
};

int main() {
  return 0;
}

/*


*/