/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3

Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // recursive dp solution (will exceed time limitation)
        // int paths = 0;
        // int uniquePaths(int m, int n) {
        //     DP(m, n, 0, 0);
        //     return paths;
        // }

        // void DP(int maxX, int maxY, int x, int y) {
        //     if(x == maxX - 1 && y == maxY - 1) {
        //         paths++;
        //         return;
        //     }
        //     if(x < maxX) DP(maxX, maxY, x + 1, y);
        //     if(y < maxY) DP(maxX, maxY, x, y + 1);
        // }

        // recursive dp solution (will exceed time limitation)
        // int uniquePaths(int m, int n) {
        //     if(m == 1 || n == 1) return 1;
        //     return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        // }
        
        int uniquePaths(int m, int n) {
            if(m == 1 || n == 1) return 1;
            vector<vector<int>> path(m, vector<int>(n , 1));
            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
                }
            }
            return path[m - 1][n - 1];
        }

        int uniquePaths_LessMemory(int m, int n) {
            if(m > n) return uniquePaths(n, m);
            vector<int> cur(m, 1);
            vector<int> top(m, 1);  // at the same column, but above the current line
            for(int i = 1; i < n; i++) {
                for(int j = 1; j < m; j++) {
                    cur[j] = cur[j - 1] + top[j];
                }
                top = cur;
            }
            return top[m - 1];
        }

        int uniquePaths_LessMemory2(int m, int n) {
            if(m > n) uniquePaths(n, m);
            vector<int> cur(m, 1);
            for(int i = 1; i < n; i++) {
                for(int j = 1; j < m; j++) {
                    cur[j] += cur[j - 1];   // cur[j] that being added is just top[j] because it has not update yet.
                }
            }
            return cur[m - 1];
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
related question: 118 Pascals Triangle

*/