/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    public:

        struct RandomListNode {
            int label;
            RandomListNode *next, *random;
            RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
        };

        RandomListNode *copyRandomList_Map(RandomListNode *head) {
            if(!head) return NULL;
            unordered_map<RandomListNode*, RandomListNode*> mp;
            RandomListNode* cur = head;
            while(cur) {
                mp[cur] = new RandomListNode(cur->label);
                cur = cur->next;
            }
            cur = head;
            while(cur) {
                mp[cur]->next = mp[cur->next];
                mp[cur]->random = mp[cur->random];
                cur = cur->next;
            }
            return mp[head];
        }

        RandomListNode *copyRandomList(RandomListNode *head) {
            if(!head) return NULL;
            RandomListNode* cur = head, *next;
            // copy node and put it after original node
            while(cur) {
                next = cur->next;
                cur->next = new RandomListNode(cur->label);
                cur->next->next = next;
                cur = next;
            }
            cur = head;
            // copy random 
            while(cur) {
                if(cur->random) {
                    cur->next->random = cur->random->next;
                }
                cur = cur->next->next;
            }

            // restore original list and format copied list
            cur = head;
            RandomListNode* fakeHead = new RandomListNode(0);
            RandomListNode* copyCur = fakeHead, *copy;
            while(cur) {
                next = cur->next->next;

                copy = cur->next;
                copyCur->next = copy;
                copyCur = copy;

                cur->next = next;
                cur = next;
            }
            return fakeHead->next;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/