/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:
Input:

   1
 /   \
2     3
 \
  5
Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
        vector<string> binaryTreePaths(TreeNode* root) {
            if(!root) return {};
            vector<string> path;
            string p = "";
            btTraversing(root, p, path);
            return path;
        }

        void btTraversing(TreeNode* root, string p, vector<string> &path) {
            if(!root) return;
            p += to_string(root->val);
            if(!root->left && !root->right) {
                path.push_back(p);
                return;
            }
            if(root->left) btTraversing(root->left, p + "->" , path);
            if(root->right) btTraversing(root->right, p + "->", path);
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/