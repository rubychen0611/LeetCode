
// @Title: 杨辉三角 (Pascal's Triangle)
// @Author: rubychen0611
// @Date: 2021-02-17 22:00:23
// @Runtime: 4 ms
// @Memory: 6.5 MB

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        for(int i = 1; i <= numRows; i++)
        {
            ans[i-1].resize(i, 1);
            for(int j = 1; j < i - 1; j++)
            {
                ans[i-1][j] = ans[i-2][j-1] + ans[i-2][j];
            }
        }
        return ans;
    }
};
