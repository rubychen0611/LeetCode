
// @Title: 三数之和 (3Sum)
// @Author: rubychen0611
// @Date: 2021-02-17 11:51:31
// @Runtime: 144 ms
// @Memory: 19.5 MB

class Solution {
private:
    void add(vector<int>& nums, int &p)
    {
        int x = nums[p];
        while( p < nums.size() && nums[p] == x)
            p++;
    }
    void minus(vector<int>& nums, int &p)
    {
        int x = nums[p];
        while(p >= 0 && nums[p] == x)
            p--;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                return ans;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int p = i + 1, q = nums.size() - 1;
            while(p < q)
            {
                int sum = nums[p] + nums[q];
                if( sum == -nums[i])
                {
                    ans.push_back(vector<int>{nums[i], nums[p], nums[q]});
                    add(nums, p);
                    minus(nums, q);
                }
                else if (sum < -nums[i])
                    add(nums, p);
                else minus(nums, q);
            }
        }
        return ans;
    }
};
