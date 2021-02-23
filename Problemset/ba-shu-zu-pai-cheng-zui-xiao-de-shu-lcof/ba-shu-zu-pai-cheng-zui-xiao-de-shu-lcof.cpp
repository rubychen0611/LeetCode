
// @Title: 把数组排成最小的数 (把数组排成最小的数 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-16 00:57:00
// @Runtime: 8 ms
// @Memory: 11.1 MB

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> numStrings;
        for(int num: nums)
        {
            numStrings.push_back(to_string(num));
        }
        sort(numStrings.begin(), numStrings.end(), [](string &s1, string &s2) -> bool{
            return s1 + s2 < s2 + s1;
        });
        string ans;
        for(string& str: numStrings)
            ans += str;
        return ans;
    }
};
