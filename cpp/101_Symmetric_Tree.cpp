/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
*/
#include <iostream>

using namespace std;

class Solution {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    public:
        int printPreorder(TreeNode* node) {
            if(node) {
                printPreorder(node->left);
                printf("%d ", node->val);
                printPreorder(node->right);
            }
        }

        bool comp(TreeNode* l, TreeNode* r) {
            if(l == NULL && r == NULL) return true;
            if(l == NULL || r == NULL) return false;
            if(l->val == r->val) {
                return comp(l->left, r->right) && comp(l->right, r->left);                
            } else return false;
        }
        
        bool isSymmetric(TreeNode* root) {
            if(root == NULL) return true;
            TreeNode *l = root->left;
            TreeNode *r = root->right;
            return comp(l, r);
        }
};

int main() {
    Solution sol;
    return 0;
}