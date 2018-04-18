/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/


#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    ListNode* l4 = new ListNode(NULL);

    public:
        
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode head(NULL);
            ListNode* l3 = &head;
            while(l1 && l2) {
                if(l1->val > l2->val) {
                    l3->next = l2;
                    l2 = l2->next;
                } else {
                    l3->next = l1;
                    l1 = l1->next;
                }
                l3 = l3->next;
            }
            l3->next = l1 ? l1 : l2;
            return head.next;
        }
};

int main() {
    Solution sol;
    return 0;
}