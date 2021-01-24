
// @Title: 反转字符串 (Reverse String)
// @Author: rubychen0611
// @Date: 2021-01-05 17:31:38
// @Runtime: 56 ms
// @Memory: 23 MB

class Solution {
public:
    void reverseString(vector<char>& s) {
        int p = 0, q = s.size() - 1;
        char tmp;
        while (p < q)
        {
            tmp = s[p];
            s[p] = s[q];
            s[q] = tmp;
            p ++;
            q --;
        }
    }
};

