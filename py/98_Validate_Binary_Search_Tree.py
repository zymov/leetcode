# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stk, prev = [], None
        while root or stk:
            while root:
                stk.append(root)
                root = root.left
            root = stk.pop()
            if prev and root.val <= prev.val:
                return False
            prev = root
            root = root.right
        return True