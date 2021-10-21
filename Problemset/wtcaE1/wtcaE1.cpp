
// @Title: 不含重复字符的最长子字符串 (不含重复字符的最长子字符串)
// @Author: rubychen0611
// @Date: 2021-10-07 17:27:50
// @Runtime: 32 ms
// @Memory: 10.8 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        unordered_map<char, int> hashMap;
        for(char ch: s) {
            hashMap.insert(pair<char, int>(ch, -1));
        }
        int left = 0, right = 0;
        int max = 0;
        for(; right < s.length(); right++) {
            //unordered_map<char, int>:: iterator it = hashMap.find(s[right]);
            if (hashMap[s[right]]!= -1) {
                int new_left = hashMap[s[right]] + 1;
                while(left < new_left) {
                    hashMap[s[left]] = -1;
                    left ++;
                }
            }
            hashMap[s[right]] = right;
            if(right - left + 1 > max) {
                max = right - left + 1;
                //cout << max << " " << left << " " << right <<endl;
            }
        }
        return max;
    }
};

