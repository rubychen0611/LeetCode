
// @Title: 用栈实现队列 (Implement Queue using Stacks)
// @Author: rubychen0611
// @Date: 2020-12-23 20:20:33
// @Runtime: 4 ms
// @Memory: 7.4 MB

class MyQueue {
private:
    stack<int> in, out;
    void In2Out()
    {
        if (out.empty())
        {
            while(!in.empty())
            {
                int x = in.top();
                in.pop();
                out.push(x);
            }
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        In2Out();
        int x = out.top();
        out.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        In2Out();
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

