
// @Title: 替换空格 (替换空格 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-13 01:16:38
// @Runtime: 4 ms
// @Memory: 6.1 MB

class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        if(len == 0)
            return s;
        int count = 0;
        for(char ch: s)
        {
            if(ch == ' ')
                count ++;
        }
        if(count == 0)
            return s;
        int new_len = len + 2 * count + 1;
        s.resize(len + 2 * count + 1);
        int p = len, q = new_len - 1;
        while(p >= 0)
        {
            if(s[p] != ' ')
                s[q--] = s[p--];
            else
            {
                s[q--] = '0';
                s[q--] = '2';
                s[q--] = '%';
                p--;
            }
        }
        return s;
    }
};
