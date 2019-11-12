# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        res, queue = [], [(root, 0)]
        while queue:
            cur, level = queue.pop()
            if cur:
                if len(res) < level + 1:
                    res.append([])
                if level % 2:
                    res[level].insert(0, cur.val)
                else:
                    res[level].append(cur.val)
                queue.append((cur.left, level + 1))
                queue.append((cur.right, level + 1))
        return res
