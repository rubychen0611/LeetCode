
// @Title: 有多少小于当前数字的数字 (How Many Numbers Are Smaller Than the Current Number)
// @Author: rubychen0611
// @Date: 2021-01-23 13:23:29
// @Runtime: 8 ms
// @Memory: 10 MB

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int hash[101] = {0};
        for(const int &x: nums)
            hash[x] ++;
        int sum = 0;
        for(int i = 0; i <= 100; i++)
        {
            int tmp = hash[i];
            hash[i] = sum;
            sum += tmp;
        }
        vector<int> ans;
        for(const int &x: nums)
            ans.push_back(hash[x]);
        return ans;
    }
};

