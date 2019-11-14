# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if inorder:
            i = inorder.index(preorder.pop(0))
            root = TreeNode(inorder[i])
            root.left = self.buildTree(preorder, inorder[0:i])
            root.right = self.buildTree(preorder, inorder[i + 1:])
            return root
