/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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

        TreeNode* prev = nullptr;

        void flatten(TreeNode* root) {
            if(!root) return;
            flatten(root->right);
            flatten(root->left);
            root->right = prev;
            root->left = nullptr;
            prev = root;
        }

        void flatten_Iter(TreeNode* root) {
            while(root) {
                if(root->left) {
                    TreeNode* t = root->left;
                    while(t->right) t = t->right;
                    t->right = root->right;
                    root->right = root->left;
                    root->left = nullptr;
                }
                root = root->right;
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/