
// @Title: 字符串的排列 (Permutation in String)
// @Author: rubychen0611
// @Date: 2021-10-07 17:06:15
// @Runtime: 4 ms
// @Memory: 7 MB

class Solution {
private:
    bool areAllZeros(int count[]) {
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        int count[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            count[s1[i] - 'a'] ++;
            count[s2[i] - 'a'] --;
        }
        if (areAllZeros(count))
            return true;
        for(int i = s1.length(); i < s2.length(); i++) {
            count[s2[i] - 'a'] --;
            count[s2[i - s1.length()] - 'a'] ++;
            if(areAllZeros(count))
                return true;
        }
        return false;
    }
};
