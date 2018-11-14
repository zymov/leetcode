/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int len = nums.size();
            if(len == 0) return 0;
            int lastMax = nums[0], curMin = lastMax, curMax = lastMax;
            for(int i = 1; i < len; i++) {
                if(nums[i] < 0) swap(curMin, curMax);
                curMin = min(nums[i], curMin * nums[i]);
                curMax = max(nums[i], curMax * nums[i]);
                lastMax = max(lastMax, curMax);
            }
            return lastMax;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/