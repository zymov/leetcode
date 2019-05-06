/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            int h = height(root);
            vector<vector<int>> v(h, vector<int>());
            levelOrder(v, root, h - 1);
            return v;
        }

        void levelOrder(vector<vector<int>> &arr, TreeNode *node, int height) {
            if(!node) return;
            arr[height].push_back(node->val);
            levelOrder(arr, node->left, height - 1);
            levelOrder(arr, node->right, height - 1);
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