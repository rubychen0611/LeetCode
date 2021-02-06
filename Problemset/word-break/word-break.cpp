
// @Title: 单词拆分 (Word Break)
// @Author: rubychen0611
// @Date: 2021-01-27 13:10:40
// @Runtime: 4 ms
// @Memory: 7.5 MB

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set;
        int min_len = INT_MAX, max_len = 0;
        for (const string & word: wordDict)
        {
            if (word.length() > max_len)
                max_len = word.length();
            if (word.length() < min_len)
                min_len = word.length();
            word_set.insert(word);
        }
        vector<bool> dp(s.length(),false);
        for (int i = min_len - 1; i < s.length(); i++)
        {
            for (int len = min_len; len <= max_len; len++)
            {
                if(i - len + 1 >= 0)
                {
                    string substr = s.substr(i - len + 1, len);
                    if (word_set.find(substr) != word_set.end() && (i - len == -1 || dp[i-len] == true)) {
                        dp[i] = true;
                        break;
                    }

                }
                else
                    break;
            }
        }
        return dp[s.length()-1];


    }
};

