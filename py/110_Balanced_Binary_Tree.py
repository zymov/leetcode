# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        return self.dfs(root) != -1
    
    def dfs(self, root: TreeNode) -> int:
        if not root:
            return 0
        left = self.dfs(root.left)
        right = self.dfs(root.right)
        if left == -1 or right == -1 or abs(left - right) > 1:
            return -1
        return 1 + max(left, right)
