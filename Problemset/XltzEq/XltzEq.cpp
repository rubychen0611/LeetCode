
// @Title: 有效的回文 (有效的回文)
// @Author: rubychen0611
// @Date: 2021-10-07 19:27:23
// @Runtime: 8 ms
// @Memory: 7.2 MB

class Solution {
private:
    bool isLegal(char ch) {
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            return true;
        return false;
    }
    bool equalsTo(char ch1, char ch2) {
        if(ch1 >= 'A' && ch1 <= 'Z')
            ch1 = tolower(ch1);
        if(ch2 >= 'A' && ch2 <= 'Z')
            ch2 = tolower(ch2);
        return ch1 == ch2;
    }
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int p1 = 0, p2 = s.length() - 1;
        while(p1 < s.length() && !isLegal(s[p1])) {
            p1 ++;
        }
        while(p2 >= 0 && !isLegal(s[p2])) {
            p2--;
        }
        while(p1 <= p2 && p1 < s.length() && p2 >= 0) {
            if(!(p1 == p2 || equalsTo(s[p1], s[p2]))) {
                return false;
            } else {
                p1 ++;
                p2 --;
            }
            while(p1 < s.length() && !isLegal(s[p1])) {
                p1 ++;
            }
            while(p2 >= 0 && !isLegal(s[p2])) {
                p2--;
            }
        }
        return true;
    }
};

