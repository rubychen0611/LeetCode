
// @Title: 只出现一次的数字 (Single Number)
// @Author: rubychen0611
// @Date: 2021-01-23 13:52:05
// @Runtime: 16 ms
// @Memory: 16.4 MB

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (const int & x: nums)
            res ^= x;
        return res;

    }
};
