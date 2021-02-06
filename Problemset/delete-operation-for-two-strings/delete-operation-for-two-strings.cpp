
// @Title: 两个字符串的删除操作 (Delete Operation for Two Strings)
// @Author: rubychen0611
// @Date: 2021-02-03 15:40:41
// @Runtime: 32 ms
// @Memory: 12 MB

class Solution {
private:
    int min(int a, int b)
    {
        return a < b ? a : b;
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        word1 = "0" + word1;
        word2 = "0" + word2;
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                if(i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if(word1[i] == word2[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            }
        }
        return dp[m][n];
    }
};

