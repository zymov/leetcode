/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        int maxArea(vector<int>& height) {
            int maxArea = 0;
            int len = height.size();
            int left = 0, right = len - 1;
            while(left < right) {
                maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
                if(height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
            return maxArea;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/