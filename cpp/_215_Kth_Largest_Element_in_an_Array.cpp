/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findKthLargest_HeapSort(vector<int>& nums, int k) {
      nums.push_back(0);
      swap(nums[0], nums[nums.size() - 1]);
      return heapSort(nums, k);
    }

    void sink(vector<int>& nums, int k, int N) {
      while(2*k <= N) {
        int j = 2*k;
        if(j < N && nums[j] < nums[j+1]) j++;
        if(nums[j] < nums[k]) break;
        swap(nums[j], nums[k]);
        k = j;
      }
    }

    int heapSort(vector<int>& nums, int k) {
      int N = nums.size() - 1;
      for(int j = N/2; j >= 1; j--)
        sink(nums, j, N);
      while(k-- > 0) {
        swap(nums[1], nums[N--]);
        sink(nums, 1, N);
      }
      return nums[N + 1];
    }

    int findKthLargest_QS(vector<int>& nums, int k) {
      int left = 0, right = nums.size() - 1;
      while(true) {
        int p = partition(nums, left, right);
        if(p == k - 1) return nums[p];
        else if(p > k - 1) right = p - 1;
        else if(p < k - 1) left = p + 1;
      }
    }

    // quick sort partition
    int partition(vector<int>& nums, int left, int right) {
      int pivot = nums[left], l = left + 1, r = right;
      while(l <= r) {
        if(nums[l] < pivot && nums[r] > pivot) {
          swap(nums[l++], nums[r--]);
        }
        if(nums[l] >= pivot)
          l++;
        if(nums[r] <= pivot)
          r--;
      }
      swap(nums[left], nums[r]);
      return r;
    }
};

int main() {
  Solution sol;
  return 0;
}

/*


*/