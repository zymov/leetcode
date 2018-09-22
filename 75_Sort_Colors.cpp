/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        // counting sort
        void sortColors(vector<int>& nums) {
            int len = nums.size();
            if(len == 0 || len == 1) return;
            vector<int> count(3, 0);    // [0 1 2] -- range is 3
            for(int i = 0; i < len; i++) {
                count[nums[i]] += 1;
            }
            int total = 0, clen = count.size();
            for(int i = 1; i < clen; i++) {
                count[i] += count[i - 1];
            }
            vector<int> output(len, 0);
            for(int i = 0; i < len; i++) {
                output[count[nums[i]] - 1] = nums[i];
                --count[nums[i]];
            }
            for(int i = 0; i < len; i++) {
                nums[i] = output[i];
            }
        }

        // two-pass 
        void sortColors(vector<int>& nums) {
            int num0 = 0, num1 = 0, num2 = 0, len = nums.size();
            for(int i = 0; i < len; i++) {
                if(nums[i] == 0) num0++;
                else if(nums[i] == 1) num1++;
                else num2++;
            }

            for(int i = 0; i < len; i++) {
                if(num0-- > 0) nums[i] = 0;
                else if(num1-- > 0) nums[i] = 1;
                else nums[i] = 2;
            }
        }

        // one-pass
        void sortColors(vector<int>& nums) {
            int len = nums.size(), pos0 = 0, pos2 = len - 1;
            for(int i = 0; i <= pos2; i++) {
                if(nums[i] == 0) {
                    swap(nums[i], nums[pos0++]);
                } else if(nums[i] == 2) {
                    swap(nums[i--], nums[pos2--]);
                }
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Counting_sort
https://www.geeksforgeeks.org/counting-sort/

*/