
// @Title: 栈的最小值 (Min Stack LCCI)
// @Author: rubychen0611
// @Date: 2020-12-23 23:39:26
// @Runtime: 48 ms
// @Memory: 15.2 MB

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

