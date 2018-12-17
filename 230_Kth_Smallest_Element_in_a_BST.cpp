/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

Follow up:
What if the BST is modified (insert/delete operations) often and 
you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/
#include <iostream>
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

    int kthSmallest(TreeNode* root, int k) {
      int n = 0;
      stack<TreeNode*> stk;
      TreeNode* cur = root;
      while(cur || stk.size()) {
        while(cur) {
          stk.push(cur);
          cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        if(++n == k) return cur->val;
        cur = cur->right;
      }
    }

    int kthSmallest_DFS(TreeNode* root, int k) {
      int count = countNode(root->left);
      if(k <= count) return kthSmallest_DFS(root->left, k);
      else if(k > count + 1) return kthSmallest_DFS(root->right, k - 1 - count);
      else return root->val;
    }

    int countNode(TreeNode* root) {
      if(root == nullptr) return 0;
      return 1 + countNode(root->left) + countNode(root->right);
    }
};

/*


*/