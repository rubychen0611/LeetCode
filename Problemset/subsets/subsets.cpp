
// @Title: 子集 (Subsets)
// @Author: rubychen0611
// @Date: 2021-02-07 00:17:17
// @Runtime: 0 ms
// @Memory: 10.6 MB

class Solution {
private:
    vector<vector<int>> ans;
    int n;
    void dfs(vector<int>& nums, vector<int> &subset, int i)
    {
        if (i == n)
        {
            ans.push_back(subset);
            return;
        }
        dfs(nums, subset, i + 1);
        subset.push_back(nums[i]);
        dfs(nums, subset, i + 1);
        subset.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        if (n == 0)
            return ans;
        vector<int> subset;
        dfs(nums, subset, 0);
        return ans;
    }
};

