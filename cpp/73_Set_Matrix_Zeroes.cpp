/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int row = matrix.size(),
                col = matrix[0].size();
            vector<int> zeroCols(col, -1);
            vector<int> zeroRows(row, -1);
            for(int i = 0; i < row; i++) {
                bool isZeroRow = false;
                for(int j = 0; j < col; j++) {
                    if(matrix[i][j] == 0) {
                        zeroCols[j] = j;
                        if(!isZeroRow) {
                            isZeroRow = true;
                            zeroRows[i] = i;
                        }
                    }
                }
            }
            for(int i = 0; i < row; i++) {
                if(zeroRows[i] == i) {
                    for(int j = 0; j < col; j++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            for(int i = 0; i < col; i++) {
                if(zeroCols[i] == i) {
                    for(int j = 0; j < row; j++) {
                        matrix[j][i] = 0;
                    }
                }
            }
        }

        // use constant space 
        void setZeroes(vector<vector<int>>& matrix) {
            int col0 = 1, row = matrix.size(), col = matrix[0].size();
            for(int i = 0; i < row; i++) {
                if(matrix[i][0] == 0) col0 = 0;
                for(int j = 1; j < col; j++) {
                    if(matrix[i][j] == 0) {
                        matrix[0][j] = matrix[i][0] = 0;
                    }
                }
            }

            // bottom-up is necessary
            for(int i = row - 1; i >= 0; i--) {
                for(int j = col - 1; j >= 1; j--) {
                    if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }
                if(col0 == 0) matrix[i][0] = 0;
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/