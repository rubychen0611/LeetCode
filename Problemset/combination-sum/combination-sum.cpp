
// @Title: 组合总和 (Combination Sum)
// @Author: rubychen0611
// @Date: 2021-02-08 15:56:04
// @Runtime: 12 ms
// @Memory: 10.7 MB

class Solution {
private:
    vector<vector<int>> ans;
    int n;
    int target;
    void dfs(const vector<int>& candidates, int last, vector<int>& path, int sum)
    {
//        for(int x : path)
//            cout << x << " ";
//        cout << endl;
        if(sum > target)
            return;
        if(sum == target)
        {
            ans.push_back(path);
            return;
        }
        for(int i = last; i < n; i++)
        {
            //cout << candidates[i]<< endl;
            path.push_back(candidates[i]);
            dfs(candidates, i, path, sum + candidates[i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        this->target = target;
        vector<int> path(1);

        for(int i = 0; i < n; i++)
        {
            path[0] = candidates[i];
            dfs(candidates, i, path, candidates[i]);
        }
        return ans;
    }
};

