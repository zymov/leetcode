/*
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
        ListNode* removeElements(ListNode* head, int val) {
            if(!head) return NULL;
            while(head && head->val == val) {
                head = head->next;
            }
            ListNode *h = head, *last = head;
            while(head) {
                if(head->val == val) {
                    last->next = head->next;
                } else {
                    last = head;                
                }
                head = head->next;
            }
            return h;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/