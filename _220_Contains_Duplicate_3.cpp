/*
Given an array of integers,
find out whether there are two distinct indices i and j in the array
such that the absolute difference between nums[i] and nums[j] is at most t
and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
typedef long long LL;

class Solution {

    public:
        // AVL Tree  O(NLogK)
        bool containsNearbyAlmostDuplicate_AVLTree(vector<int>& nums, int k, int t) {
            if (k <= 0 || t < 0) return false;
            int size = nums.size();
            set<LL> order;
            for (int i = 0; i < size; i++) {
                auto it = order.lower_bound((LL)nums[i] - (LL)t);
                if (it != order.end() && *it <= (LL)nums[i] + (LL)t)
                    return true;
                if (i >= k) order.erase(nums[i - k]);
                order.insert(nums[i]);
            }
            return false;
        }

        // Bucket  O(N)
        bool containsNearbyAlmostDuplicate_Bucket(vector<int>& nums, int k, int t) {
            if (k <= 0 || t < 0) return false;
            unordered_map<LL, LL> keyToVal;
            LL div = (LL)t + 1;     // edge case: t = 0
            for (int i = 0; i < nums.size(); i++) {
                LL num = (LL)nums[i];
                LL key = num / div;
                if(num < 0) key--;
                if (keyToVal.find(key) != keyToVal.end()
                    || keyToVal.find(key + 1) != keyToVal.end() && keyToVal[key + 1] - num <= t
                    || keyToVal.find(key - 1) != keyToVal.end() && num - keyToVal[key - 1] <= t)
                    return true;
                if (i >= k) keyToVal.erase((LL)nums[i - k] / div);
                keyToVal[key] = num;
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
