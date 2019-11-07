# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        h = ListNode(0)
        h.next = head
        n -= m
        i, prev = 0, h
        while m > 1:
            prev = prev.next
            m -= 1
        cur = prev.next
        while n > 0:
            tmp = cur.next
            cur.next = tmp.next
            tmp.next = prev.next
            prev.next = tmp
            n -= 1
        return h.next

