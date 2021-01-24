
// @Title: 验证回文字符串 Ⅱ (Valid Palindrome II)
// @Author: rubychen0611
// @Date: 2021-01-04 15:53:13
// @Runtime: 84 ms
// @Memory: 25.3 MB

class Solution {
private:
    bool ifPalindrome(string s, int & p, int & q)
    {
        while(p < q && s[p] == s[q])
        {
            p ++;
            q --;
        }
        if (p >= q)
            return true;
        return false;
    }
public:
    bool validPalindrome(string s) {
        int p = 0, q = s.length() - 1;
        if (ifPalindrome(s, p, q))
            return true;
        int p1, q1;
        if (s[p] == s[q-1])
        {
            p1 = p;
            q1 = q-1;
            if (ifPalindrome(s, p1, q1))
                return true;
        }
        if (s[p+1] == s[q])
        {
            p++;
            if (ifPalindrome(s, p, q))
                return true;
        }
        return false;
    }
};

