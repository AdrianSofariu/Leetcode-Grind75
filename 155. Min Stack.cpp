/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/

class MinStack {
    //This problem can be solved in multiple ways.
    //Using 2 stacks or a stack of pairs
    //Using 1 stack, a min variable and a special encoding for new minimums on the stack
    //Using a self build stack with SLL Nodes
    //I will use the last one, as many people on leetcode said the interviewer would like you to design
    //a new data strucutre not use an existing one
private:
    class Node {
        public:
            int val;
            int min;
            Node* next;
            
            Node(int v, int m, Node* n) : val{v}, min{m}, next{n} {}
    };

    Node* head = NULL;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(head == NULL)
            head = new Node(val, val, NULL);
        else
        {
            head = new Node(val, min(val, head->min), head);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
