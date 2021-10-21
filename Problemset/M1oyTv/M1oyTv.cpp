
// @Title: 含有所有字符的最短字符串 (含有所有字符的最短字符串)
// @Author: rubychen0611
// @Date: 2021-10-07 23:22:39
// @Runtime: 16 ms
// @Memory: 15.8 MB

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";
        unordered_map<char, int> countMap;
        for(char ch: t) {
            if(countMap.find(ch) != countMap.end()) {
                countMap[ch] ++;
            } else {
                countMap.insert(pair<char, int> (ch, 1));
            }
        }
        int left = 0, right = 0;
        int min = s.length() + 1;
        int lack = t.length();
        string ans = "";
        for(; right < s.length(); right++) {
            if(countMap.find(s[right]) != countMap.end()) {
                if(countMap[s[right]] > 0)  // 缺少这个字母
                    lack --;
                countMap[s[right]]--;
                while(lack == 0 && left <= right) {
                    if(right - left + 1 < min) {
                        min = right - left + 1;
                        ans = s.substr(left, right - left + 1);
                    }
                    if(countMap.find(s[left]) != countMap.end()) {
                        countMap[s[left]] ++;
                        if(countMap[s[left]] > 0) {
                            lack ++;
                        }
                    }
                    left ++;
                }
            }
        }
        return ans;
    }
};

