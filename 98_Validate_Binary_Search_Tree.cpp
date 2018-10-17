/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:

Input:
    2
   / \
  1   3
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

        bool isValidBST(TreeNode* root) {
            if(!root) return true;
            if(!isValidLeft(root->left, root->val) || !isValidRight(root->right, root->val)) return false;
            return isValidBST(root->left) && isValidBST(root->right);
        }
        
        bool isValidLeft(TreeNode* root, int value) {
            if(!root) return true;
            if(root->val >= value) return false;
            return isValidLeft(root->left, value) && isValidLeft(root->right, value);
        }

        bool isValidRight(TreeNode* root, int value) {
            if(!root) return true;
            if(root->val <= value) return false;
            return isValidRight(root->left, value) && isValidRight(root->right, value);
        }

        // inorder tranversal 
        bool isValidBST(TreeNode* root) {
            if(!root) return true;
            stack<TreeNode*> stk;
            TreeNode* pre = nullptr;
            while(root || !stk.empty()) {
                while(root) {
                    stk.push(root);
                    root = root->left;
                }
                root = stk.top();
                stk.pop();
                if(pre && root->val <= pre->val) return false;
                pre = root;
                root = root->right;
            }
            return true;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/