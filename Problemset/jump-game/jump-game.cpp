
// @Title: 跳跃游戏 (Jump Game)
// @Author: rubychen0611
// @Date: 2018-07-05 16:46:56
// @Runtime: 248 ms
// @Memory: N/A

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), j;
        bool *grid = new bool[n];
        for (j = 0; j < n; j++)
        {
            grid[j] = false;
        }
        grid[0] = true;
        if(n == 1) return true;
        for (j = 0; j < n; j++)
        {
            if (grid[j] == true && nums[j] > 0)
            {
                for (int t = 1; t <= nums[j]; t++)
                {
                    if (j + t < n)
                    {
                        grid[j + t] = true;
                        if (j + t == n - 1)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
