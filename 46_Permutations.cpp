/*
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
            swapRecursive(nums, res, 0);
            return res;
        }

        void swapRecursive(vector<int>& nums, vector<vector<int>>& res, int pos) {
            int len = nums.size();
            if(pos == len) {
                res.push_back(nums);
                return;
            }
            for(int i = pos; i < len; i++) {
                swap(nums[pos], nums[i]);   //try all elements on a fixed position, and move the position towards the end
                swapRecursive(nums, res, pos + 1);
                swap(nums[pos], nums[i]);
            }
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*
http://forum.codecall.net/topic/64715-how-to-generate-all-permutations/

*/