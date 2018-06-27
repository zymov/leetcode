/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty 
and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

    public:
        int majorityElement(vector<int>& nums) {
            if(nums.size() == 1) return nums[0];
            unordered_map<int, int> hash;
            for(int i = 0; i < nums.size(); i++) {
                if(hash.find(nums[i]) != hash.end()) {
                    hash[nums[i]]++;
                    if(hash[nums[i]] > nums.size() / 2) {
                        return nums[i];
                    }
                } else {
                    hash[nums[i]] = 1;
                }
            }
        }
        
        int majorityElement_Better(vector<int>& nums) {
            int major = nums[0];
            int count = 1;
            for(int i = 1; i < nums.size(); i++) {
                if(major == nums[i]) {
                    count++;
                } else if(count == 0) {
                    major = nums[i];
                    count = 1;
                } else {
                    count--;
                }
            }
            return major;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*
http://www.cs.utexas.edu/~moore/best-ideas/mjrty/

*/