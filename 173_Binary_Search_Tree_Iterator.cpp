/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
#include <iostream>
#include <stack>

using namespace std;

class BSTIterator {
    public:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };
        
        stack<TreeNode*> stk;
        BSTIterator(TreeNode *root) {
            // saveNodes(root);
            getAllNode(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !stk.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode* t = stk.top();
            stk.pop();
            // saveNodes(t->right);
            return t->val;
        }

        void saveNodes(TreeNode* root) {
            while(root) {
                stk.push(root);
                root = root->left;
            }
        }

        // post-order traversal
        void getAllNode(TreeNode* root) {
            if(!root) return;
            TreeNode* cur = root;
            stack<TreeNode*> nodeStk;
            while(cur || !nodeStk.empty()) {
                while(cur) {
                    nodeStk.push(cur);
                    cur = cur->right;
                }
                cur = nodeStk.top();
                nodeStk.pop();
                stk.push(cur);
                cur = cur->left;
            }
        }
};

int main() {
    return 0;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */