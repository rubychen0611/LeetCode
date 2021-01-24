
// @Title: 最长回文串 (Longest Palindrome)
// @Author: rubychen0611
// @Date: 2021-01-24 00:32:29
// @Runtime: 0 ms
// @Memory: 6.5 MB

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count_map;
        for(const char& ch: s)
        {
            if(count_map.find(ch) == count_map.end())
                count_map[ch] = 1;
            else
                count_map[ch] ++;
        }
        int ans = 0;
        bool odd = false;
        for (unordered_map<char, int>:: iterator it = count_map.begin(); it != count_map.end(); it++)
        {
            int n = it -> second;
            if (n % 2 == 0)
                ans += n;
            else {
                ans += (n - 1);
                odd = true;
            }
        }
        if (odd)
            ans ++;
        return ans;
    }
};

