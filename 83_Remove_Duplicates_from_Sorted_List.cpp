/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:
Input: 1->1->2
Output: 1->2

Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
*/
#include <iostream>

using namespace std;

class Solution {

    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode(int x) : val(x), next(NULL) {}
     * };
     */

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode *h = head;

            while(head != NULL && head->next != NULL) {
                if(head->val == head->next->val) {
                    ListNode *pos = head->next;
                    head->next = pos->next;
                    free(pos);
                } else {
                    head = head->next;
                }
            }

            return h;

        }
        
};

int main() {
    Solution sol;
    return 0;
}