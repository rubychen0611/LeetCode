
// @Title: 数据流中的第 K 大元素 (Kth Largest Element in a Stream)
// @Author: rubychen0611
// @Date: 2021-02-16 16:30:51
// @Runtime: 32 ms
// @Memory: 19.4 MB

class KthLargest {
private:
    int k;   
   priority_queue<int, vector<int>, greater<int>> Q;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(const int x: nums)
        {
            add(x);
        }
    }
    
    int add(int val) {
        if(Q.size() < k)
            Q.push(val);
        else if(val > Q.top())
        {
            Q.pop();
            Q.push(val);
        }
        return Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
