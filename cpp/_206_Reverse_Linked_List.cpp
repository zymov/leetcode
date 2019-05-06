/*
Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
        // Iterative Method
        ListNode* reverseList_Iterative(ListNode* head) {
            ListNode *current = head, *prev = NULL, *next = NULL;
            while(current != NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return prev;
        }
        
        // Recursive Method
        ListNode* reverseList_Recursive(ListNode* head) {
            if(head == NULL || head->next == NULL) return head;
            ListNode *tail = reverseList_Recursive(head->next);
            head->next->next = head;
            head->next = NULL;
            return tail;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/