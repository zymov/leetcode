/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
#include <iostream>

using namespace std;

class Solution {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    public:
        bool hasPathSum(TreeNode* root, int sum) {
            if(root && !root->left && !root->right && root->val == sum) return true;
            return hasPath2Sum(root, sum, root);
        }
        
        bool hasPath2Sum(TreeNode* root, int sum, TreeNode* ROOT) {
            if(!root) return false;
            if(root->val == sum && root != ROOT && !root->left && !root->right) {
                return true;
            } else {
                return hasPath2Sum(root->left, sum - root->val, ROOT) || 
                    hasPath2Sum(root->right, sum - root->val, ROOT);
            } 
        }
};

int main() {
    Solution sol;
    return 0;
}