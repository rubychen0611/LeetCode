
// @Title: 打家劫舍 II (House Robber II)
// @Author: rubychen0611
// @Date: 2021-02-03 14:56:23
// @Runtime: 0 ms
// @Memory: 7.6 MB

class Solution {
private:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int rob_origin(vector<int>& nums, int start, int end)
    {
        int n = end - start + 1;
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[start];
        if (n == 2)
            return max(nums[start], nums[end]);
        int f2 = nums[start], f1 = max(nums[start], nums[start + 1]), cur;
        for(int i = start + 2; i <= end; i++)
        {
            cur = max(f1, f2 + nums[i]);
            f2 = f1;
            f1 = cur;
        }
        return cur;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int rob1 = rob_origin(nums, 0, n-2);
        int rob2 = rob_origin(nums, 1, n-1);
        return max(rob1, rob2);
    }
};

