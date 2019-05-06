/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode resHead(0), *res = &resHead;
            int carry = 0;
            while(l1 || l2 || carry) {
                int l1_val = l1 ? l1->val : 0;
                int l2_val = l2 ? l2->val : 0;
                int s = l1_val + l2_val + carry;
                carry = s / 10;
                res->next = new ListNode(s % 10);
                res = res->next;
                l1 = l1 ? l1->next : l1;
                l2 = l2 ? l2->next : l2;
            }
            return resHead.next;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/