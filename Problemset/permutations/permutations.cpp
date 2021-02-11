
// @Title: 全排列 (Permutations)
// @Author: rubychen0611
// @Date: 2021-02-06 23:23:15
// @Runtime: 4 ms
// @Memory: 8 MB

class Solution {
private:
    vector<bool> used;
    vector<vector<int>> ans;
    int n;
    void dfs(vector<int>& nums, vector<int> permutation, int i)
    {
        if(i == n)
        {
            ans.push_back(permutation);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(!used[j])
            {
                permutation[i] = nums[j];
                used[j] = true;
                dfs(nums, permutation, i + 1);
                used[j] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        if(n == 0)
            return ans;
        used = vector<bool>(n, false);
        vector<int> permutation(n);
        dfs(nums, permutation, 0);
        return ans;
    }
};

