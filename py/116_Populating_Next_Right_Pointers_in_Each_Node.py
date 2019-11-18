# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        r = root
        while root and root.left:
            next = root.left
            while root:
                root.left.next = root.right
                if root.next:
                    root.right.next = root.next.left
                root = root.next
            root = next
        return r
