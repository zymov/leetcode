/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up:
This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int front = 0, end = nums.size() - 1, mid;
            while(front <= end) {
                mid = front + (end - front) / 2;
                if(nums[mid] == target) return true;
                if(nums[front] == nums[mid] && nums[mid] == nums[end]) {
                    ++front; --end;
                } else if(nums[front] <= nums[mid]) {
                    if(nums[front] <= target && target < nums[mid]) end = mid - 1;
                    else front = mid + 1;
                } else {
                    if(nums[mid] < target && target <= nums[end]) front = mid + 1;
                    else end = mid - 1;
                }
            }
            return false;
        }

};

int main() {
    Solution sol;
    return 0;
}

/*


*/