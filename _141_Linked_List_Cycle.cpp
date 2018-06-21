/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
        bool hasCycle(ListNode *head) {
            if(!head) return false;
            ListNode *walker = head;
            ListNode *runner = head;
            while(runner->next != NULL && runner->next->next != NULL) {
                walker = walker->next;
                runner = runner->next->next;
                if(walker->val == runner->val) {
                    return true;
                }
            }
            return false;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Cycle_detection

*/