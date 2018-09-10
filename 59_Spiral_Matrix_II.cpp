/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:
Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            if(n == 0) return {};
            vector<vector<int>> res (n, vector<int>(n, 0));
            int x = 0,          y = 0,
                xBegin = 0,     yBegin = 0,
                xEnd = n - 1,   yEnd = n - 1,
                numb = 1;
            while(numb <= n*n) {
                res[y][x] = numb++;
                if(y == yBegin && x < xEnd) {
                    x++;
                } else if (x == xEnd && y < yEnd) {
                    y++;
                } else if (y == yEnd && y != yBegin && x > xBegin) {
                    x--;
                } else if (x == xBegin && x != xEnd && y > yBegin) {
                    if(y == yBegin + 1) {
                        ++xBegin;
                        ++yBegin;
                        --xEnd;
                        --yEnd;
                        x = xBegin;
                        y = yBegin;
                    } else y--;
                }
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