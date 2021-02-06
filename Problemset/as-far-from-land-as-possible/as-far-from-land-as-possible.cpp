
// @Title: 地图分析 (As Far from Land as Possible)
// @Author: rubychen0611
// @Date: 2021-02-02 13:06:31
// @Runtime: 52 ms
// @Memory: 17 MB

class Solution {
private:
    int min (int a, int b)
    {
        return a < b ? a : b;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int max = 0;
        vector<vector<int>> dp(m, vector<int> (n, INT_MAX - 1));
        for (int  i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
        for (int  i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    if (i + 1 < m)
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    if (j + 1 < n)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
                if (dp[i][j] > max)
                    max = dp[i][j];
            }

        }
        if (max == 0 || max == INT_MAX - 1)
            return -1;
        return max;
    }
};

