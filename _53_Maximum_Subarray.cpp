/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int maxSubArray(vector<int>& nums) {
            int i, sum = 0, maxSum = nums[0];
            for(i = 0; i < nums.size(); i++) {
                sum += nums[i];
                if(sum > maxSum) {
                    maxSum = sum;
                }
                if(sum < 0) {
                    sum = 0;
                }
            }
            return maxSum;
        }
        
};

int main() {
    Solution sol;
    vector<int> n = {-2,-1};
    cout << sol.maxSubArray(n) << endl;
    return 0;
}