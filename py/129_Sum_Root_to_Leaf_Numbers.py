# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        return self.dfs(root, 0)

    def dfs(self, node: TreeNode, sum: int):
        if not node:
            return 0
        sum = sum * 10 + node.val
        if not node.left and not node.right:
            return sum
        return self.dfs(node.left, sum) + self.dfs(node.right, sum)
