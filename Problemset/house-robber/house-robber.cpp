
// @Title: 打家劫舍 (House Robber)
// @Author: rubychen0611
// @Date: 2021-01-25 20:58:53
// @Runtime: 0 ms
// @Memory: 7.5 MB

class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        int f1 = max(nums[0], nums[1]), f2 = nums[0], cur;
        for (int i = 2; i < n; i++)
        {
            cur = max(f2 + nums[i], f1);
            f2 = f1;
            f1 = cur;
        }
        return cur;
    }
};

