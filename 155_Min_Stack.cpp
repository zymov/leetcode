/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
#include <iostream>

using namespace std;

class MinStack {
    struct node {
        int val;
        int curMin;
        node *next;
        node(int x, int y) : val(x), curMin(y), next(NULL) {}
    };

    private:
        node *topPtr;
        int min;
        
    public:
        /** initialize your data structure here. */
        MinStack() {
            topPtr = NULL;
            min = INT_MAX;
        }
        
        void push(int x) {
            if(min > x) {
                min = x;
            }
            struct node *n = new node(x, min);
            if(topPtr != NULL) {
                n->next = topPtr;
            }
            topPtr = n;
        }
        
        void pop() {
            if(topPtr == NULL) return;
            node *temp = topPtr;
            topPtr = topPtr->next;
            if(topPtr == NULL) {
                min = INT_MAX;
            } else {
                min = topPtr->curMin;
            }
            free(temp);
            
        }
        
        int top() {
            return topPtr->val;
        }
        
        int getMin() {
            return topPtr->curMin;
        }
        /**
         * Your MinStack object will be instantiated and called as such:
         * MinStack obj = new MinStack();
         * obj.push(x);
         * obj.pop();
         * int param_3 = obj.top();
         * int param_4 = obj.getMin();
         */
        
};

int main() {
    int min = INT_MAX;
    cout << min << endl;
    return 0;
}

/*


*/