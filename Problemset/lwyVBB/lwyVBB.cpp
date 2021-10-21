
// @Title: 外星语言是否排序 (外星语言是否排序)
// @Author: rubychen0611
// @Date: 2021-10-08 23:36:27
// @Runtime: 0 ms
// @Memory: 9.2 MB


class Solution {
private:
    int hash[26];
    bool isLE(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        int min = len1 < len2 ? len1 : len2;
        for(int i = 0; i < min; i++) {
            if(hash[s1[i] - 'a']  < hash[s2[i] - 'a']) {
                return true;
            }
            if(hash[s1[i] - 'a']  > hash[s2[i] - 'a']) {
                return false;
            }
        }
        if(len1 <= len2)
            return true;
        return false;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; i++) {
            hash[order[i] - 'a'] = i;
        }
        for(int i = 0; i < words.size() - 1; i++) {
            if(!isLE(words[i], words[i+1])) {
                return false;
            }
        }
        return true;
    }
};

