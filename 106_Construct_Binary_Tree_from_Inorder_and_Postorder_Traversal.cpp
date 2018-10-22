/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int index = postorder.size() - 1;
            return getSubTree(inorder, postorder, index, 0, index);
        }

        TreeNode* getSubTree(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inStart, int inEnd) {
            if(postIndex < 0 || inStart > inEnd) return NULL;
            TreeNode* root = new TreeNode(postorder[postIndex]);
            auto pos = distance(inorder.begin(), find(inorder.begin() + inStart, inorder.begin() + inEnd, postorder[postIndex]));
            postIndex--;
            root->right = getSubTree(inorder, postorder, postIndex, pos + 1, inEnd);
            root->left = getSubTree(inorder, postorder, postIndex, inStart, pos - 1);
            return root;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/