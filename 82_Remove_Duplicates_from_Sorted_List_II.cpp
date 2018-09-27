/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
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

        ListNode* deleteDuplicates(ListNode* head) {
            if(!head) return NULL;
            ListNode *dummy = new ListNode(head->val + 1);  // distinguish from first value
            dummy->next = head;
            ListNode *prev = dummy;
            ListNode *first = dummy;    // head of no duplicate list
            while(head != NULL && head->next != NULL) {
                if(head->val != prev->val && head->val != head->next->val) {
                    first->next = head;
                    first = first->next;
                }
                prev = head;
                head = head->next;
            }
            if(prev->val != head->val) {    // deal with the last element
                first->next = head;
                first = first->next;
            }
            first->next = NULL;
            return dummy->next;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/