
// @Title: 找到字符串中所有字母异位词 (Find All Anagrams in a String)
// @Author: rubychen0611
// @Date: 2021-10-07 17:06:46
// @Runtime: 8 ms
// @Memory: 8.5 MB

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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length() > s.length())
            return ans;
        int count[26] = {0};

        for(int i = 0; i < p.length(); i++) {
            count[p[i] - 'a'] ++;
            count[s[i] - 'a'] --;
        }
        if (areAllZeros(count))
            ans.push_back(0);
        for(int i = p.length(); i < s.length(); i++) {
            count[s[i] - 'a'] --;
            count[s[i - p.length()] - 'a'] ++;
            if(areAllZeros(count))
                ans.push_back(i - p.length() + 1);
        }
        return ans;
    }
};
