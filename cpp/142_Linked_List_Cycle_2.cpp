/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.

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
        ListNode *detectCycle(ListNode *head) {
            if(!head) return nullptr;
            ListNode *walker = head;
            ListNode *runner = head;
            while(runner->next != NULL && runner->next->next != NULL) {
                walker = walker->next;
                runner = runner->next->next;
                if(walker == runner) {
                    ListNode *entry = head;
                    while(entry != walker) {
                        entry = entry->next;
                        walker = walker->next;
                    }
                    return entry;
                }
            }
            return nullptr;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Cycle_detection

*/