/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int len = nums.size();
            int twoSum = 0;
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < len; i++) {
                int j = i + 1, k = len - 1;
                int target = -nums[i];
                if(target < 0) break;
                while(j < k) {
                    twoSum = nums[j] + nums[k];
                    if(twoSum < target) {
                        j++;
                    } else if(twoSum > target) {
                        k--;
                    } else {
                        int nj = nums[j], nk = nums[k];
                        res.push_back({nums[i], nj, nk});
                        while(j < k && nums[j] == nj) j++;
                        while(j < k && nums[k] == nk) k--;
                    }
                }
                while(i + 1 < len && nums[i] == nums[i + 1]) i++;
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