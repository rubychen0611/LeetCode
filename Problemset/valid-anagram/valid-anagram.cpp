
// @Title: 有效的字母异位词 (Valid Anagram)
// @Author: rubychen0611
// @Date: 2021-01-23 14:35:13
// @Runtime: 4 ms
// @Memory: 7.1 MB

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m1[26]={0}, m2[26]={0};
        for(char c: s)
            m1[c - 'a'] ++;
        for(char c: t)
            m2[c - 'a'] ++;
        for (int i = 0; i < 26; i++)
            if (m1[i] != m2[i])
                return false;
        return true;
    }
};

