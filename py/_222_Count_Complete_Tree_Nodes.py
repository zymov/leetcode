"""
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
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root: return 0
        curL = root.left
        curR = root.left
        num = 1
        while curR:
            curL = curL.left
            curR = curR.right
            num <<= 1
        return num + self.countNodes(root.left) if curL else self.countNodes(root.right)
