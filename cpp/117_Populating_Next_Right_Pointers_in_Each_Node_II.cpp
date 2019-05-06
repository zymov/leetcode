/*
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.

Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7

After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/
#include <iostream>

using namespace std;

class Solution {
    public:
        struct TreeLinkNode {
            int val;
            TreeLinkNode *left;
            TreeLinkNode *right;
            TreeLinkNode *next;
            TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {};
        };

        void connect(TreeLinkNode *root) {
            TreeLinkNode *now;
            TreeLinkNode *head;     // left most element at next level;
            TreeLinkNode *tail;     // pointer travel from head to right most element at next level;
            now = root;
            while(now) {
                if(now->left) {
                    if(tail) {
                        tail->next = now->left;
                        tail = tail->next;
                    } else {
                        head = tail = now->left;
                    }
                }
                if(now->right) {
                    if(tail) {
                        tail->next = now->right;
                        tail = tail->next;
                    } else {
                        head = tail = now->right;
                    }
                }
                now = now->next;    // "now" level was already populated in the previous round
                if(!now) {
                    now = head;
                    head = tail = nullptr;
                }
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/