/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
Given the sorted linked list: [-10,-3,0,5,9],
One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/
#include <iostream>

using namespace std;

class Solution {


    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    public:
        TreeNode* sortedListToBST(ListNode* head) {
            return toBST(head, NULL);
        }

        TreeNode* toBST(ListNode *head, ListNode *tail) {
            if(head == tail) return NULL;
            if(head->next == tail) {
                return new TreeNode(head->val);
            } 
            ListNode *fast = head, *slow = head;
            while(fast != tail && fast->next != tail) {
                slow = slow->next;
                fast = fast->next->next;
            }
            // now slow is at middle
            TreeNode *root = new TreeNode(slow->val);
            root->left = toBST(head, slow);
            root->right = toBST(slow->next, tail);
            return root;
        }




        TreeNode* Insert(ListNode *node, TreeNode *T) {
            if(T == NULL) {
                T = new TreeNode(node->val);
                T->left = T->right = NULL;
            } else if (node->val < T->val) {
                T->left = Insert(node, T->left);
                if(height(T->left) - height(T->right) == 2) {
                    if(node->val < T->left->val) {
                        singleRotateLeft(T);
                    } else {
                        doubleRotateLeft(T);
                    }
                }
            } else if (node->val > T->val) {
                T->right = Insert(node, T->right);
                if(height(T->right) - height(T->left) == 2) {
                    if(node->val < T->right->val) {
                        doubleRotateRight(T);
                    } else {
                        singleRotateRight(T);
                    }
                }
            }
            return T;
        }

        int height(TreeNode *T) {
            if(T == NULL) return 0;
            return 1 + max(height(T->left), height(T->right));
        }

        TreeNode* singleRotateLeft(TreeNode *T) {
            TreeNode *TL = T->left;
            T->left = TL->right;
            TL->right = T;
            return TL;
        }

        TreeNode* singleRotateRight(TreeNode *T) {
            TreeNode *TR = T->right;
            T->right = TR->left;
            TR->left = T;
            return TR;
        }

        TreeNode* doubleRotateLeft(TreeNode *T) {
            T->left = singleRotateRight(T->left);
            return singleRotateLeft(T);
        }

        TreeNode* doubleRotateRight(TreeNode *T) {
            T->right = singleRotateLeft(T->right);
            return singleRotateRight(T);
        }
};

int main() {
    Solution sol;
    return 0;
}