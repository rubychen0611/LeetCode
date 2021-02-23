
// @Title: 错误的集合 (Set Mismatch)
// @Author: rubychen0611
// @Date: 2021-02-17 14:35:03
// @Runtime: 24 ms
// @Memory: 20.9 MB

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int repeat, miss;
        for(int i = 0; i < n; i++)
        {
            int j = abs(nums[i]);
            if(nums[j - 1] > 0)
            {
                nums[j - 1] = - nums[j - 1];
            }
            else
                repeat = j;
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0 )
                miss = i+1;
        }
        return vector<int>{repeat, miss};
    }
};
