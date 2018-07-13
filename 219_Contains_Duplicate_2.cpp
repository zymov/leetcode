/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int size = nums.size();
            unordered_map<int, int> hash;
            for(int i = 0; i < size; i++) {
                if(hash.find(nums[i]) == hash.end() || i - hash[nums[i]] > k) {
                    hash[nums[i]] = i;
                } else {
                    return true;
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