/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            if(matrix.size() == 0 || matrix[0].size() == 0) return {};
            int xEnd = matrix[0].size() - 1,
                yEnd = matrix.size() - 1,
                x = 0, y = 0,
                beginX = 0, beginY = 0;
            vector<int> res;
            while(beginX <= xEnd && beginY <= yEnd) {
                res.push_back(matrix[y][x]);
                if(y == beginY && x < xEnd) {
                    x++;
                } else if (x == xEnd && y < yEnd) {
                    y++;
                } else if (y == yEnd && y != beginY && x > beginX) {
                    x--;
                } else if (x == beginX && x != xEnd && y > beginY) {
                    if (y == beginY + 1) {
                        ++beginX;
                        ++beginY;
                        --xEnd;
                        --yEnd;
                        x = beginX;
                        y = beginY;
                    } else y--;
                } else break;
            }
            return res;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/