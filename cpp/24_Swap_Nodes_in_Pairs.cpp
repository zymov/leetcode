/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
*/
#include <iostream>

using namespace std;

class Solution {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    public:
        ListNode* swapPairs(ListNode* head) {
            if(!head || !head->next) return head;
            ListNode *node = head, *temp = nullptr, *lastNode = nullptr;
            ListNode *newHead = head->next;
            while(node->next != NULL) {
                temp = node->next->next;
                node->next->next = node;
                node->next = temp;                
                if(lastNode) lastNode->next = node->next;
                lastNode = node;
                node = node->next;
            }
            return newHead;
        }

        // still don't understand how this solution makes 1->4 in 1->2->3->4 to 2->1->4->3
        ListNode* swapPairs_PP(ListNode* head) {
            ListNode **pp = &head, *a, *b;
            while((a = *pp) && (b = a->next)) {
                a->next = b->next;
                b->next = a;
                *pp = b;
                if(*pp) {
                    cout << (*pp)->val << endl;
                }
                pp = &(a->next);
            }
            return head;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/