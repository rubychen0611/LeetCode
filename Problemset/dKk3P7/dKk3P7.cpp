
// @Title: 有效的变位词 (有效的变位词)
// @Author: rubychen0611
// @Date: 2021-10-08 23:15:37
// @Runtime: 4 ms
// @Memory: 7.2 MB

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s == t)
            return false;
        int count[26] = {0};
        for(char ch: s) {
            count[ch - 'a'] ++;
        }
        for(char ch: t) {
            count[ch - 'a'] --;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0)
                return false;
        }
        return true;
    }
};

