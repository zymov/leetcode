/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.

Follow up:
Could you do this in one pass?
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *H = head, *fakeHead = head;
            while(n > 0) {
                fakeHead = fakeHead->next;
                n--;
            }
            if(fakeHead == NULL) {
                head = head->next;
                return head;
            }
            while(fakeHead->next) {
                H = H->next;
                fakeHead = fakeHead->next;
            }
            H->next = H->next->next;
            return head;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/