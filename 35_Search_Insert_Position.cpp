/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int searchInsert(vector<int>& nums, int target) {
            int i = 0, len = nums.size();
            while(i < len && nums[i] < target) {
                ++i;
            }
            return i;
        }

        int searchInsert_BinarySearch(vector<int>& nums, int target) {
            int len = nums.size();
            int low = 0, high = len - 1, mid;
            while(low <= high) {
                mid = low + (high - low) / 2;                
                if(target < nums[mid]) {
                    high = mid - 1;
                } else if(target > nums[mid]) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            }
            return low;     // low will never less than 0
        }
        
};

int main() {
    Solution sol;
    vector<int> l = {1,2,3,5,6};
    cout << sol.searchInsert_BinarySearch(l, 5) << endl;
    cout << sol.searchInsert_BinarySearch(l, 4) << endl;
    cout << sol.searchInsert_BinarySearch(l, 0) << endl;
    cout << sol.searchInsert_BinarySearch(l, 8) << endl;
    return 0;
}