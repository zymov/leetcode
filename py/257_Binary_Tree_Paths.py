from typing import List

# Definition for a binary tree node.


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if not root:
            return []
        stack, res = [(root, "")], []
        while stack:
            node, path = stack.pop()
            if not node.left and not node.right:
                res.append(path + str(node.val))
            if node.left:
                stack.append((node.left, path + str(node.val) + "->"))
            if node.right:
                stack.append((node.right, path + str(node.val) + "->"))
        return res

    def binaryTreePaths2(self, root: TreeNode) -> List[str]:
        if not root:
            return []
        res = []
        self.dfs(res, "", root)
        return res

    def dfs(self, res: List[str], path: str, root: TreeNode):
        if not root.left and not root.right:
            res.append(path + str(root.val))
        if root.left:
            self.dfs(res, path + str(root.val) + "->", root.left)
        if root.right:
            self.dfs(res, path + str(root.val) + "->", root.right)
