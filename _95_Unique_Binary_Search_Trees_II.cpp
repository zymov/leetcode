/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:
Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]

Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
    
        vector<TreeNode*> generateTrees(int n) {
            if(n == 0) return vector<TreeNode*>();
            return gen(1, n);
        }

        vector<TreeNode*> gen(int start, int end) {
            vector<TreeNode*> res;
            if(start > end) {
                res.push_back(nullptr);
            } else if(start == end) {
                res.push_back(new TreeNode(start));
            } else {
                for(int i = start; i <= end; i++) {
                    vector<TreeNode*> left_subtree = gen(start, i - 1);
                    vector<TreeNode*> right_subtree = gen(i + 1, end);
                    // combine all possible ways of left and right to the root
                    for(int j = 0; j < left_subtree.size(); j++) {
                        for(int k = 0; k < right_subtree.size(); k++) {
                            TreeNode* root = new TreeNode(i);
                            root->left = left_subtree[j];
                            root->right = right_subtree[k];
                            res.push_back(root);
                        }
                    }
                }
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