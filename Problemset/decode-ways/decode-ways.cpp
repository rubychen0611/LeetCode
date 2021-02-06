
// @Title: 解码方法 (Decode Ways)
// @Author: rubychen0611
// @Date: 2021-01-27 12:33:10
// @Runtime: 0 ms
// @Memory: 6 MB

class Solution {
public:
    int numDecodings(string s) {
        int i;
        if(s[0] == '0')
            return 0;

        vector<int>dp(s.length());
        dp[0] = 1;
        for(i = 1; i < s.length(); i++)
        {
            if (s[i] >= '1' && s[i] <= '9')
                dp[i] = dp[i-1];
            if ((s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6')))
            {
                if (i == 1)
                    dp[i] += 1;
                else
                    dp[i] += dp[i-2];
            }
        }
        return dp[s.length()-1];
    }
};

