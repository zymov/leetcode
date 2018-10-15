/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

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

        // G(n) = G(0)*G(n-1) + G(1)*G(n-2) + G(2)*G(n - 3) + ... + G(n-1)*G(0) 
        int numTrees(int n) {
            vector<int> g(n + 1, 0);
            g[0] = g[1] = 1;
            for(int i = 2; i <= n; i++) {
                for(int j = 1; j <= i; j++) {
                    g[i] += g[j - 1] * g[i - j];
                }
            }
            return g[n];
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
https://www.youtube.com/watch?v=YDf982Lb84o

*/