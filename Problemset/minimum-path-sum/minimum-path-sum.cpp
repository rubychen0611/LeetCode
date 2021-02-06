
// @Title: 最小路径和 (Minimum Path Sum)
// @Author: rubychen0611
// @Date: 2021-01-26 12:39:13
// @Runtime: 8 ms
// @Memory: 9.7 MB

class Solution {
private:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = grid[0][0];
        for(int j = 1; j < n; j++)
        {
            f[0][j] = f[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < m; i++)
        {
            f[i][0] = f[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        }
        return f[m-1][n-1];
    }
};

