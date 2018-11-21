/*
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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

        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            BFS(root, 1, res);
            return res;
        }

        void BFS(TreeNode* root, int depth, vector<int>& result) {
            if(!root) return;
            if(result.size() < depth) result.push_back(root->val);
            BFS(root->right, depth + 1, result);
            BFS(root->left, depth + 1, result);
        }
};

int main() {
    return 0;
}

/*


*/