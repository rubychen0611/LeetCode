
// @Title: 全排列 II (Permutations II)
// @Author: rubychen0611
// @Date: 2021-02-06 23:42:17
// @Runtime: 12 ms
// @Memory: 9.5 MB

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
            if(j > 0 && nums[j-1] == nums[j] && !used[j-1]) //保证在填第 \textit{idx}idx 个数的时候重复数字只会被填入一次即可。
                continue;
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        if(n == 0)
            return ans;
        used = vector<bool>(n, false);
        vector<int> permutation(n);
        sort(nums.begin(), nums.end());
        dfs(nums, permutation, 0);
        return ans;
    }
};

