
// @Title: 数据流的第 K 大数值 (数据流的第 K 大数值)
// @Author: rubychen0611
// @Date: 2021-10-12 16:58:06
// @Runtime: 32 ms
// @Memory: 19.4 MB

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap; 
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(int num: nums) {
            heap.push(num);
        }
        while(heap.size() > k) {
            heap.pop();
        }
    }
    
    int add(int val) {
        if(!heap.empty() && heap.size() == k && val <= heap.top()) {
            return heap.top();
        }
        heap.push(val);
        while(heap.size() > k) {
            heap.pop();
        }
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
