/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            inorderRecursive(root, res);
            return res;
        }

        void inorderRecursive(TreeNode* root, vector<int> &res) {
            if(!root) return;
            inorderRecursive(root->left, res);
            res.push_back(root->val);
            inorderRecursive(root->right, res);
        }
        
        vector<int> inorderTraversalIterative(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> stk;
            TreeNode *cur = root;
            while(cur || stk.size()) {
                while(cur) {
                    stk.push(cur);
                    cur = cur->left;
                }
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
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