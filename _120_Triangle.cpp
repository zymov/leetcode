/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int size = triangle.size();
            vector<int> minPaths = triangle.back();
            for(int level = size - 2; level >= 0; level--) {    // start at second last row
                for(int i = 0; i <= level; i++) {
                    minPaths[i] = min(minPaths[i], minPaths[i + 1]) + triangle[level][i];
                }
            }
            return minPaths[0];
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
dynamic programming

*/