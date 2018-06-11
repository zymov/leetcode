/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:
[
   [5,4,11,2],
   [5,8,4,5]
]

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
        vector<vector<int>> pathSum(TreeNode* root, int sum) {
            vector<vector<int>> paths;
            vector<int> path;
            findPaths(root, sum, path, paths);
            return paths;
        }

        void findPaths(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &paths) {
            if(!root) return;
            path.push_back(root->val);
            if(root->val == sum && !root->left && !root->right) {
                paths.push_back(path);
            }
            findPaths(root->left, sum - root->val, path, paths);
            findPaths(root->right, sum - root->val, path, paths);
            path.pop_back();    // the most important line
        }
};

int main() {
    Solution sol;
    return 0;
}