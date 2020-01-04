from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []
        self.bfs(root, 1, res)
        return res

    def bfs(self, root: TreeNode, depth: int, result: List[int]):
        if not root:
            return
        if len(result) < depth:
            result.append(root.val)
        self.bfs(root.right, depth + 1, result)
        self.bfs(root.left, depth + 1, result)
