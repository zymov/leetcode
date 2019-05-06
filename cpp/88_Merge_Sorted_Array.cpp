/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = 0, j = 0, k = 0;
            vector<int> arr(m + n);
            while(i < m && j < n) {
                if(nums1[i] <= nums2[j]) {
                    arr[k++] = nums1[i++];
                } else {
                    arr[k++] = nums2[j++];
                }
            }
            while(i < m) {
                arr[k++] = nums1[i++];
            }
            while(j < n) {
                arr[k++] = nums2[j++];
            }
            nums1 = arr;
        }

        void notMySolution(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;
            while(i >= 0 && j >= 0) {
                if(nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }
            if(j >= 0) {
                nums1[k--] = nums2[j--];
            }

            for(int q = 0; q < m + n; q++) {
                cout << nums1[q] << endl;
            }
        }
        
};

int main() {
    Solution sol;
    vector<int> m = {1,2,3,12};
    vector<int> n = {2,5,6,8,11};
    // sol.merge(m, 3, n, 3);
    sol.notMySolution(m, 4, n, 5);
    return 0;
}