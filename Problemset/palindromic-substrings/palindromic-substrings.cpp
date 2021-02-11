
// @Title: 回文子串 (Palindromic Substrings)
// @Author: rubychen0611
// @Date: 2021-02-10 23:14:12
// @Runtime: 20 ms
// @Memory: 7.3 MB

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        for(int len = 0; len < n; len ++)
        {
            for(int i = 0; i < n; i++)
            {
                int j = i + len;
                if (j >= n)
                    break;
                if (s[i] == s[j] && (len < 2 || dp[i+1][j-1]))
                {    
                    dp[i][j] = true;
                    ans ++;
                }
            }
        }
        return ans;
    }
};
