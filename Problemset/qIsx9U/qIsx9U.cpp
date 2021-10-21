
// @Title: 滑动窗口的平均值 (滑动窗口的平均值)
// @Author: rubychen0611
// @Date: 2021-10-12 11:46:24
// @Runtime: 16 ms
// @Memory: 13.6 MB

class MovingAverage {
private:
    queue<int> Q;
    int size;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        Q.push(val);
        sum += val;
        if(Q.size() > size) {
            sum -= Q.front();
            Q.pop();
        }
        return double(sum) / Q.size(); 
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
