/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
*/
#include <iostream>

using namespace std;

class Solution {
  public:
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    int countNodes(TreeNode* root) {
      if(!root) return 0;
      TreeNode *curL(root->left), *curR(root->left);
      int num = 1;
      // check the left subtree is perfect or not
      while(curR) {
        curL = curL->left;
        curR = curR->right;
        num <<= 1;
      }
      // If curL exists, which means the right side is a perfect binary tree! So we can just check the left subtree recursively.
      return num + (curL ? countNodes(root->left) : countNodes(root->right));
    }
};

int main() {
  return 0;
}

/*


*/