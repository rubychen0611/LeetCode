
// @Title: 按权重随机选择 (Random Pick with Weight)
// @Author: rubychen0611
// @Date: 2021-03-03 11:42:10
// @Runtime: 88 ms
// @Memory: 39.1 MB

class Solution {
private:
    vector<int> sum;
    int binary_search(int target)
    {
        int left = 0, right = sum.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(sum[mid] == target)
                return mid;
            if(sum[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

public:
    Solution(vector<int>& w):sum(move(w)) {
        partial_sum(sum.begin(), sum.end(), sum.begin());   // 求前缀和
    }
    
    int pickIndex() {
        int random_pos = rand() % sum.back() + 1;
        int idx = binary_search(random_pos);
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
