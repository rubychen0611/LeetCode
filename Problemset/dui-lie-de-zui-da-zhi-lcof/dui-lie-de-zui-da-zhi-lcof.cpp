
// @Title: 队列的最大值 (队列的最大值 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-16 16:07:58
// @Runtime: 128 ms
// @Memory: 47.7 MB

class MaxQueue {
private:
    queue<int> Q;
    deque<int> max_Q;
public:
    MaxQueue() {
        
    }
    
    int max_value() {
        if(Q.empty())
            return -1;
        return max_Q.front();
    }
    
    void push_back(int value) {
        Q.push(value);
        while(!max_Q.empty() && max_Q.back() < value)
            max_Q.pop_back();
        max_Q.push_back(value);
    }
    
    int pop_front() {
        if(Q.empty())
            return -1;
        int val = Q.front();
        if(val == max_Q.front())
            max_Q.pop_front();
        Q.pop();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
