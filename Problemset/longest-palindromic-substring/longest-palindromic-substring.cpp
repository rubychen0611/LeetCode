
// @Title: 最长回文子串 (Longest Palindromic Substring)
// @Author: rubychen0611
// @Date: 2021-02-12 23:59:29
// @Runtime: 276 ms
// @Memory: 29.3 MB

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int max_len = 0, max_i, max_j;
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
                    if(len + 1 > max_len)
                    {
                        max_len = len + 1;
                        max_i = i;
                    }
                }
            }
        }
        return s.substr(max_i, max_len);
    }
};
