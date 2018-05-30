/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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

    int currentLevel;
    vector<vector<int>> arr;

    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            int h = height(root);
            vector<vector<int>> v(h, vector<int>());
            levelOrder(v, root, 0);
            return v;
        }

        void levelOrder(vector<vector<int>> &arr, TreeNode *node, int level) {
            if(!node) return;
            arr[level].push_back(node->val);
            levelOrder(arr, node->left, level + 1);
            levelOrder(arr, node->right, level + 1);
        }

        int height(TreeNode *root) {
            if(root == NULL) return 0;
            return 1 + max(height(root->left), height(root->right));
        }
        
};

int main() {
    Solution sol;
    return 0;
}