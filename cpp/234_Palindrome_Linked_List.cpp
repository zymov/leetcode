/*
Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true

Follow up:
Could you do it in O(n) time and O(1) space?
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
        bool isPalindrome(ListNode* head) {
            if(!head || !head->next) return true;
            ListNode *slow = head, *fast = head;
            while(fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            slow->next = reverseLinkedList(slow->next);
            slow = slow->next;
            while(slow) {
                if(slow->val != head->val) return false;
                slow = slow->next;
                head = head->next;
            }
            return true;
        }

        ListNode* reverseLinkedList(ListNode* head) {
            ListNode *pre = NULL, *next = NULL;
            while(head) {
                next = head->next;
                head->next = pre;
                pre = head;
                head = next;
            }
            return pre;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/