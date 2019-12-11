# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        dummy = ListNode(0)
        dummy.next, node, prev = head, head.next, head
        while node:
            if prev.val > node.val:
                next = node.next
                prev.next = next
                tmp = None
                while node.val > head.val:
                    tmp = head
                    head = head.next
                if tmp:
                    tmp.next = node
                else:
                    dummy.next = node
                node.next = head
                head = dummy.next
                node = next
            else:
                prev = node
                node = node.next
        return dummy.next
