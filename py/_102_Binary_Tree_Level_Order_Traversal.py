"""
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
"""

from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        h = self.height(root)
        result = [[] for i in range(h)]
        self.BFS(root, 0, result)
        return result

    def BFS(self, root: TreeNode, level: int, result: List[List[int]]):
        if not root:
            return
        result[level].append(root.val)
        self.BFS(root.left, level + 1, result)
        self.BFS(root.right, level + 1, result)


    def height(self, root: TreeNode) -> int:
        if not root:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))
