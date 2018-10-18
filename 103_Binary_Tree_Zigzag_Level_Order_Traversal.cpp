/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, 
from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };

        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(!root) return vector<vector<int>>();
            vector<vector<int>> res;
            queue<TreeNode*> Q;
            Q.push(root);
            bool L2R = true;
            while(!Q.empty()) {
                int size = Q.size();
                vector<int> row(size);
                for(int i = 0; i < size; i++) {
                    TreeNode* temp = Q.front();
                    Q.pop();
                    int index = L2R ? i : size - 1 - i;
                    row[index] = temp->val;
                    if(temp->left) Q.push(temp->left);
                    if(temp->right) Q.push(temp->right);
                }
                L2R = !L2R;
                res.push_back(row);
            }
            return res;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/