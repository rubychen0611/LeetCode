
// @Title: 用队列实现栈 (Implement Stack using Queues)
// @Author: rubychen0611
// @Date: 2020-12-23 23:30:23
// @Runtime: 4 ms
// @Memory: 7.2 MB

class MyStack {
private:
    queue<int> Q[2];
    int cur;
public:
    /** Initialize your data structure here. */
    MyStack() {
        cur = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q[cur].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x;
        while(Q[cur].size() > 1)
        {
            x = Q[cur].front();
            Q[cur].pop();
            Q[!cur].push(x);
        }
        x = Q[cur].front();
        Q[cur].pop();
        cur = !cur;
        return x;
    }
    
    /** Get the top element. */
    int top() {
        int x;
        while(Q[cur].size() > 0)
        {
            x = Q[cur].front();
            Q[cur].pop();
            Q[!cur].push(x);
        }
        cur = !cur;
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q[cur].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

