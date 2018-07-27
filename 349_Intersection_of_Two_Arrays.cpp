/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, bool> m;
            vector<int> res;
            for(int i = 0; i < nums1.size(); i++) {
                m[nums1[i]] = true;
            }
            for(int i = 0; i < nums2.size(); i++) {
                if(m[nums2[i]]) {
                    res.push_back(nums2[i]);
                    m[nums2[i]] = false;
                }
            }
            return res;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/