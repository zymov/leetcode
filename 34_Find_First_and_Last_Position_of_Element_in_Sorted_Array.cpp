/*
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int len = nums.size();
            int low = 0, high = len - 1, mid;
            vector<int> res;
            while(low < high) {
                mid = low + (high - low) / 2;
                if(target < nums[mid]) {
                    high = mid - 1;
                } else if(target > nums[mid]){
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }

            if(low == high && target != nums[low]) return {-1, -1};
            res.push_back(high);
            low = high, high = len - 1;
            while(low < high) {
                mid = low + (high - low) / 2 + 1;   // +1 makes the mid biased to the high but not low
                if(target < nums[mid]) {
                    high = mid - 1;
                } else if(target > nums[mid]){
                    low = mid + 1;
                } else {
                    low = mid;
                }
            }
            res.push_back(low);
            return res;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/