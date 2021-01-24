
// @Title: 字符串中的第一个唯一字符 (First Unique Character in a String)
// @Author: rubychen0611
// @Date: 2021-01-23 23:23:58
// @Runtime: 20 ms
// @Memory: 10.4 MB

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (const char& ch: s)
            count[ch - 'a'] ++;
        for (int i = 0; i < s.length(); i++)
            if(count[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};

