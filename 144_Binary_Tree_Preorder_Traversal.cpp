/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/
#include <iostream>
#include <vector>
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

        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res;
            stack<TreeNode*> stk;
            while(root || stk.size()) {
                if(!root) {
                    root = stk.top();
                    stk.pop();
                }
                if(root->right) {
                    stk.push(root->right);
                }
                res.push_back(root->val);
                root = root->left;
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