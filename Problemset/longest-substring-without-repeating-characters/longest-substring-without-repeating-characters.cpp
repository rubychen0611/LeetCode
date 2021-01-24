
// @Title: 无重复字符的最长子串 (Longest Substring Without Repeating Characters)
// @Author: rubychen0611
// @Date: 2021-01-24 01:02:40
// @Runtime: 24 ms
// @Memory: 10.6 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1 = 0, p2 = 0, max = 0;
        unordered_map<char, int> hash_map;
        for(p2 = 0; p2 < s.length(); p2++)
        {
            char ch = s[p2];
            if(hash_map.find(ch) != hash_map.end())
            {
                for(; p1 < hash_map[ch] + 1; p1 ++)
                {
                    unordered_map<char, int>::iterator it = hash_map.find(s[p1]);
                    hash_map.erase(it);
                }
            }
            hash_map[ch] = p2;
            if(p2 - p1 + 1 > max)
                max = p2 - p1 + 1;
        }
        return max;
    }
};

