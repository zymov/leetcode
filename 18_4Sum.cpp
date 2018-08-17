/*
Given an array nums of n integers and an integer target, 
are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
The solution set must not contain duplicate quadruplets.

Example:
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> res;
            sort(nums.begin(), nums.end());
            int len = nums.size(), subTarget = 0;
            for(int i = 0; i < len; i++) {
                for(int j = i + 1; j < len; j++) {
                    subTarget = target - nums[i] - nums[j];
                    int k = j + 1, h = len - 1;
                    while(k < h) {
                        if(subTarget - nums[k] < nums[h]) {
                            h--;
                        } else if(subTarget - nums[k] > nums[h]) {
                            k++;
                        } else {
                            int nk = nums[k], nh = nums[h];
                            res.push_back({nums[i], nums[j], nk, nh});
                            while(k < h && nums[k] == nk) k++;
                            while(k < h && nums[h] == nh) h--;
                        }
                    }
                    while(j + 1 < len && nums[j + 1] == nums[j]) j++;
                }
                while(i + 1 < len && nums[i + 1] == nums[i]) i++;
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