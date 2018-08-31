/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());
            swapRecursive(nums, res, 0);
            return res; 
        }

        void swapRecursive(vector<int> nums, vector<vector<int>>& res, int pos) {
            int len = nums.size();
            if(pos == len) {
                res.push_back(nums);
                return;
            }
            for(int i = pos; i < len; i++) {
                if(i != pos && nums[i] == nums[pos]) continue;
                swap(nums[pos], nums[i]);
                swapRecursive(nums, res, pos + 1);
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