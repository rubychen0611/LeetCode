
// @Title: 调整数组顺序使奇数位于偶数前面 (调整数组顺序使奇数位于偶数前面 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-15 20:26:04
// @Runtime: 16 ms
// @Memory: 17.7 MB

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        for(int j = 0; j < n; j++)
        {
            if(nums[j] % 2 == 1)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
