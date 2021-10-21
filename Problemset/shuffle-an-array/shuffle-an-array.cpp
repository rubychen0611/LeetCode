
// @Title: 打乱数组 (Shuffle an Array)
// @Author: rubychen0611
// @Date: 2021-03-01 11:34:43
// @Runtime: 148 ms
// @Memory: 88.2 MB

class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        origin.assign(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>shuffled(origin);
        int n = shuffled.size();
        for(int i = n-1; i >= 0; i--)
        {
            swap(shuffled[i], shuffled[rand() % (i + 1)]); // 反向洗牌，0~i之间的随机数
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
