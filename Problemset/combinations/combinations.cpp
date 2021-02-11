
// @Title: 组合 (Combinations)
// @Author: rubychen0611
// @Date: 2021-02-07 00:09:35
// @Runtime: 384 ms
// @Memory: 128.8 MB

class Solution {
private:
    //vector<bool> used;
    vector<vector<int>> ans;
    int k, n;
    void dfs(vector<int> combination, int i)
    {
        if(i == k)
        {
            ans.push_back(combination);
            return;
        }
        int start;
        if (i == 0)
            start = 1;
        else
            start = combination[i-1] + 1;
        if(start > n)
            return;
        for(int j = start; j <= n; j++)
        {
            //if(!used[j])
            //{
            //    used[j] = true;
                combination[i] = j;
                dfs(combination, i + 1);
            //    used[j] = false;
            //}
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        this ->n = n;
        this -> k = k;
        //used = vector<bool>(n+1, false);
        vector<int> combination(k);
        dfs(combination, 0);
        return ans;
    }
};

