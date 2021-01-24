
// @Title: 找不同 (Find the Difference)
// @Author: rubychen0611
// @Date: 2021-01-23 23:28:41
// @Runtime: 4 ms
// @Memory: 6.3 MB

class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        for(const char& ch: s)
            count[ch-'a'] ++;
        for(const char& ch: t)
        {
            if(count[ch-'a'] > 0)
                count[ch-'a'] --;
            else return ch;
        }
        return 'a';
    }
};

