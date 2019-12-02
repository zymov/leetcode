# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return
        tmp = head
        while tmp:
            newNode = Node(tmp.val, None, None)
            newNode.next = tmp.next
            tmp.next = newNode
            tmp = tmp.next.next
        tmp = head
        while tmp:
            if tmp.random:
                tmp.next.random = tmp.random.next
            tmp = tmp.next.next
        newHead = head.next
        pold = head
        pnew = newHead
        while pnew.next:
            pold.next = pnew.next
            pold = pold.next
            pnew.next = pold.next
            pnew = pnew.next
        pold.next = None
        pnew.next = None
        return newHead

