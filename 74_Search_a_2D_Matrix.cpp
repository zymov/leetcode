/*
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int len = matrix.size(), row = -1;
            if(len == 0 || matrix[0].size() == 0) return false;
            if(target < matrix[0][0]) return false;
            for(int i = 0; i < len; i++) {
                if(target < matrix[i][0]) break;
                row++;
            }
            int low = 0, high = matrix[row].size() - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(matrix[row][mid] < target) low = mid + 1;
                else if(matrix[row][mid] > target) high = mid - 1;
                else return true;
            }
            return false;
        }

        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if(matrix.empty()) return false;
            int row = matrix.size(), col = matrix[0].size();
            int low = 0, high = row * col - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(matrix[mid / col][mid % col] < target)
                    low = mid + 1;
                else if(matrix[mid / col][mid % col] > target)
                    high = mid - 1;
                else return true;
            }
            return false;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/