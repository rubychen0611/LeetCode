
// @Title: 数据流中的中位数 (数据流中的中位数  LCOF)
// @Author: rubychen0611
// @Date: 2021-02-16 12:22:18
// @Runtime: 104 ms
// @Memory: 40.7 MB

class MedianFinder {
private:
    int size;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size % 2 == 0)   // 偶数，最大堆 + 1
        {
            if(!min_heap.empty() && min_heap.top() < num)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else max_heap.push(num);
            
        }
        else    // 奇数，最小堆 + 1
        {
            if(!max_heap.empty() && max_heap.top() > num)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else
                min_heap.push(num);
            
        }
        size ++;
    }
    
    double findMedian() {
        if(size % 2 == 0)
            return (min_heap.top() + max_heap.top()) / 2.0;
        else return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
