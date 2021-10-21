
// @Title: 最大子序和 (Maximum Subarray)
// @Author: rubychen0611
// @Date: 2021-10-17 15:57:40
// @Runtime: 112 ms
// @Memory: 66.1 MB

class Solution {
private:
    int max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maxSubArray(vector<int>& nums) {
        int lastMax = nums[0];
        int ans = lastMax;
        for(int i = 1; i < nums.size(); i++) {
            lastMax = max(lastMax + nums[i], nums[i]);
            ans = max(ans, lastMax);
        }
        return ans;
    }
};
