/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
#include <iostream>

using namespace std;

class Solution {
    public:
        struct ListNode {
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
        };

        void reorderList(ListNode* head) {
            if(!head || !head->next || !head->next->next) return;
            ListNode *p1 = head, *p2 = head;
            while(p2->next && p2->next->next) {
                p1 = p1->next;
                p2 = p2->next->next;
            }
            // cut off from middle
            ListNode *head2 = p1->next;
            p1->next = NULL;
            ListNode *temp, *pre = NULL;    // *pre = NULL ensures the correctness of list length
            while(head2) {
                temp = head2->next;
                head2->next = pre;
                pre = head2;
                head2 = temp;
            }
            p1 = head; p2 = pre;
            ListNode *t;
            while(p1) {
                t = p1->next;
                p1->next = p2;
                p1 = p1->next;
                p2 = t;
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/