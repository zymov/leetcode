/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted array: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    public:

        TreeNode* sortedArrayToBST(vector<int>& nums) {
            int len = nums.size();
            if(len == NULL) return NULL;
            if(len == 1) {
                TreeNode *t = new TreeNode(nums[0]);
                t->val = nums[0];
                return t;
            } else {
                int mid = len / 2;
                TreeNode *root = new TreeNode(nums[mid]);
                vector<int> leftLeave(nums.begin(), nums.begin() + mid);
                vector<int> rightLeave(nums.begin() + mid + 1, nums.end());
                root->left = sortedArrayToBST(leftLeave);
                root->right = sortedArrayToBST(rightLeave);
                return root;
            }
            
        }
        
};

int main() {
    Solution sol;
    return 0;
}