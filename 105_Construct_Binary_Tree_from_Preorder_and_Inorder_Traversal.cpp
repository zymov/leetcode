/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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

        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int rootIdx = 0;
            return getSubRoot(preorder, inorder, rootIdx, 0, inorder.size() - 1);
        }

        TreeNode* getSubRoot(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int inStart, int inEnd) {
            if(rootIdx > preorder.size() - 1 || inStart > inEnd) return NULL;
            TreeNode* newRoot = new TreeNode(preorder[rootIdx]);
            // find current preorder root in inorder 
            auto k = distance(inorder.begin(), find(inorder.begin() + inStart, inorder.begin() + inEnd, preorder[rootIdx]));
            rootIdx++;  // rootIdx is a reference
            newRoot->left = getSubRoot(preorder, inorder, rootIdx, inStart, k - 1);
            newRoot->right = getSubRoot(preorder, inorder, rootIdx, k + 1, inEnd);
            return newRoot;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
