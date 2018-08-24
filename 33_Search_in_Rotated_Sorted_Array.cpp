/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1


[4,5,6,7,8,1,2,3]
8
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int search(vector<int>& nums, int target) {
            int len = nums.size();
            if(len == 0) return -1;
            int minIndex = getMinIndex(nums);
            if(target == nums[minIndex]) return minIndex; 
            int front = 0, end = len - 1, mid;
            if(target <= nums[end]) front = minIndex; 
            else end = minIndex - 1;
            while(front <= end) {
                mid = front + (end - front) / 2;
                if(target < nums[mid]) {
                    end = mid - 1;
                } else if(target > nums[mid]) {
                    front = mid + 1;
                } else {
                    return mid;
                }
            }
            return -1;
        }

        // find the min value index
        int getMinIndex(vector<int>& nums) {
            int front = 0, end = nums.size() - 1, mid;
            while(front < end) {
                mid = front + (end - front) / 2;
                if(nums[mid] > nums[end]) front = mid + 1;
                else end = mid;
            }
            return front;
        }
                
};

int main() {
    Solution sol;
    return 0;
}

/*


*/