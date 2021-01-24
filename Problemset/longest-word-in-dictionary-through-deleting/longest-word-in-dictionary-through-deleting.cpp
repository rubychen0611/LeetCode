
// @Title: 通过删除字母匹配到字典里最长单词 (Longest Word in Dictionary through Deleting)
// @Author: rubychen0611
// @Date: 2021-01-04 19:06:52
// @Runtime: 88 ms
// @Memory: 24.7 MB

class Solution {
private:
    bool ifDeletedMatches(string s, string x)
    {
        int p = 0;
        for (char ch: x)
        {
            while(p < s.length() && s[p] != ch)
                p++;
            if (s[p] != ch)
                return false;
            p++;
        }
        return true;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        int max = 0;
        string max_str = "";
        for (string x: d)
        {
            if (x.length() > max && ifDeletedMatches(s, x))
            {
                max = x.length();
                max_str = x;
            }
            else if (x.length() == max && x < max_str && ifDeletedMatches(s, x))
            {
                max_str = x;
            }
        }
        return max_str;
    }
};

