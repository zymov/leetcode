# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
"""
                circle begin                meet
----------m----------|>-------------x---------|------>
---------------------|>------------------n----------->

2(m + x) = m + n + x
    -> m = n - x
"""
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head:
            return None
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                tmp = head
                while tmp != slow:
                    tmp = tmp.next
                    slow = slow.next
                return tmp
        return None

