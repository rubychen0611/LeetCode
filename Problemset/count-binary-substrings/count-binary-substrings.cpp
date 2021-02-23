
// @Title: 计数二进制子串 (Count Binary Substrings)
// @Author: rubychen0611
// @Date: 2021-02-12 21:21:01
// @Runtime: 28 ms
// @Memory: 13.9 MB

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> repeat;
        int count = 1;
        char last = s[0];
        for(int i = 1; i < s.length(); i++)
        {
            if(last == s[i])
                count ++;
            else{
                repeat.push_back(count);
                count = 1;
                last = s[i];
            }
        }
        repeat.push_back(count);
        int ans = 0;
        for(int i = 1; i < repeat.size(); i++)
        {
            ans += min(repeat[i-1], repeat[i]);
        }
        return ans;
    }
};
