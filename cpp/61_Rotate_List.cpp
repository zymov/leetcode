/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL

Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL

Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == NULL) return head;
            int len = 1;
            ListNode *current = head, *prev = nullptr, *h = head;
            while(head->next) {
                prev = head;
                head = head->next;
                current = head;
                len++;
            }
            current->next = h;

            if(len <= k) k %= len;
            int restLen = len - k;
            while(restLen > 1) {
                h = h->next;
                restLen--;
            }
            ListNode *res = h->next;
            h->next = NULL;
            return res;
        }
    
};

int main() {
    Solution sol;
    return 0;
}

/*


*/