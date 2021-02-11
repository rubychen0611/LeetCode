
// @Title: 组合总和 II (Combination Sum II)
// @Author: rubychen0611
// @Date: 2021-02-08 18:10:16
// @Runtime: 8 ms
// @Memory: 10.3 MB

class Solution {
private:
    vector<vector<int>> ans;
    int n;
    int target;
    vector<bool> used;
    void dfs(const vector<int>& candidates, int startIdx, vector<int>& path, int sum)
    {
        if(sum > target)
            return;
        if(sum == target)
        {
            ans.push_back(path);
            return;
        }

        for(int i = startIdx; i < n; i++)
        {
            //cout << candidates[i]<< endl;
            if(i > startIdx && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, path, sum + candidates[i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        if(n == 0)
            return ans;
        this->target = target;
        sort(candidates.begin(), candidates.end());
        used.resize(n, false);
        vector<int> path;

        dfs(candidates, 0, path, 0);

        return ans;
    }
};

