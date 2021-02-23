
// @Title: 最小窗口子序列 (Minimum Window Subsequence)
// @Author: rubychen0611
// @Date: 2021-02-18 11:08:53
// @Runtime: 340 ms
// @Memory: 433.6 MB

class Solution {
public:
    string minWindow(string S, string T) {
        int s_len = S.length();
        int t_len = T.length();
        vector<vector<int>> next(s_len, vector<int>(26, -1));
        for(int i = s_len - 2; i >= 0; i--)
        {
            for(int j = 0; j < 26; j++)
            {
                if(S[i+1] - 'a' == j)
                    next[i][j] = i + 1;
                else 
                    next[i][j] = next[i+1][j];
            }
        }
        int i;
        if(T[0] == S[0])
            i = 0;
        else
            i = next[0][T[0]-'a'];
        int min = INT_MAX;
        string ans = "";
        while(i != -1)
        {
            int k = i;
            for(int j = 1; j < t_len; j++)
            {
                k = next[k][T[j] - 'a'];
                if(k == -1)
                    break;
            }
            if(k != -1)
            {
                if(k - i + 1 < min)
                {
                    min = k - i + 1;
                    ans = S.substr(i, min);
                }
            }
            i = next[i][T[0]-'a'];
        }
        return ans;
    }
};
