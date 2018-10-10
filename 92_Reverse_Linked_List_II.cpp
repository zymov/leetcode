/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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

        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if(m == n) return head;
            n -= m;
            ListNode *h = new ListNode(0);
            h->next = head;
            ListNode *prev = h;
            while(--m) prev = prev->next;
            ListNode *cur = prev->next;
            while(n--) {
                ListNode *move = cur->next;
                cur->next = move->next;
                move->next = prev->next;
                prev->next = move;
            }
            return h->next;
        }
};
/*


*/