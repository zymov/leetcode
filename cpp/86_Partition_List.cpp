/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
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

        ListNode* partition(ListNode* head, int x) {
            ListNode n1(0), n2(0);
            ListNode *p1 = &n1, *p2 = &n2;
            while(head != NULL) {
                if(head->val < x) {
                    p1->next = head;
                    p1 = p1->next;
                } else {
                    p2->next = head;
                    p2 = p2->next;
                }
                head = head->next;
            }
            p2->next = NULL;
            p1->next = n2.next;
            return n1.next;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/