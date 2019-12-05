# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return
        p1, p2 = head, head
        while p2.next and p2.next.next:
            p1 = p1.next
            p2 = p2.next.next
        p2 = p1.next
        p1.next = None

        prev, cur = None, p2
        while cur:
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp

        p1, p2 = head, prev
        while p1:
            tmp = p1.next
            p1.next = p2
            p1 = p1.next
            p2 = tmp
        return head
