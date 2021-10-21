
// @Title: 字符串中的所有变位词 (字符串中的所有变位词)
// @Author: rubychen0611
// @Date: 2021-10-07 17:05:16
// @Runtime: 8 ms
// @Memory: 8.6 MB

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

