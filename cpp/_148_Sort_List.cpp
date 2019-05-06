/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
        
        ListNode* sortList(ListNode* head) {
            if(!head || !head->next) return head;
            int len = 0;
            ListNode *cur = head;
            while(cur) {
                len++;
                cur = cur->next;
            }
            ListNode dummy(0);
            dummy.next = head;
            ListNode *tail, *left, *right;
            for(int step = 1; step < len; step += step) { // step <<= 1
                cur = dummy.next;
                tail = &dummy;
                tail->next = cur;
                while(cur) {
                    left = cur;
                    right = split(left, step);
                    cur = split(right, step);
                    tail = merge(left, right, tail);
                }
            }
            return dummy.next;
        }

        // devide the linked list into two list, the first contains first n nodes, return the second list.
        ListNode* split(ListNode* head, int n) {
            while(head && n > 1) {
                head = head->next;
                n--;
            }
            if(!head) return NULL;
            ListNode *second = head->next;
            head->next = NULL;
            return second;
        }

        ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
            ListNode *cur = head;
            while(l1 && l2) {
                if(l1->val > l2->val) {
                    cur->next = l2;
                    cur = l2;
                    l2 = l2->next;
                } else {
                    cur->next = l1;
                    cur = l1;
                    l1 = l1->next;
                }
            }
            cur->next = l1 ? l1 : l2;
            while(cur->next) cur = cur->next;
            return cur;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/