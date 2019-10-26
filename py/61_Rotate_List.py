class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return
        l, h = 1, head
        while h and h.next:
            h = h.next
            l += 1
        remain = l - k % l
        if k == 0 or remain == 0:
            return head
        h.next = head
        while remain:
            h = h.next
            remain -= 1
        newHead = h.next
        h.next = None
        return newHead

