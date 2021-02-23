
// @Title: 丢失的数字 (Missing Number)
// @Author: rubychen0611
// @Date: 2021-02-17 14:25:50
// @Runtime: 20 ms
// @Memory: 17.5 MB

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 1; i <= n; i++)
            s ^= i;
        for(int x: nums)
        {
            s ^= x;
        }
        return s;
    }
};
