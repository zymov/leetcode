# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        return self.traverse(root.left, root.right)
                
    def traverse(self, l: TreeNode, r: TreeNode) -> bool:
        if not l and not r:
            return True
        if l and r and l.val == r.val:
            return self.traverse(l.left, r.right) and self.traverse(l.right, r.left)
        return False