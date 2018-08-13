/*
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int res = nums[0] + nums[1] + nums[2], len = nums.size(), threeSum;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < len; i++) {
                int j = i + 1, k = len - 1;
                int subTarget = target - nums[i];
                while(j < k) {
                    threeSum = nums[i] + nums[j] + nums[k];
                    if(abs(threeSum - target) < abs(res - target)) {
                        res = threeSum;
                        if(res == target) return res;
                    }
                    threeSum > target ? k-- : j++;
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