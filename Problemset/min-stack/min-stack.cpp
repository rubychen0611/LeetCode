
// @Title: 最小栈 (Min Stack)
// @Author: rubychen0611
// @Date: 2020-12-23 20:40:45
// @Runtime: 32 ms
// @Memory: 14.7 MB

class MinStack {
private:
    stack<int> st, min_st;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        if (min_st.empty() || x <= min_st.top())
        {
            min_st.push(x);
            return;
        }
    }
    
    void pop() {
        int x = st.top();
        if(x == min_st.top())
            min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

