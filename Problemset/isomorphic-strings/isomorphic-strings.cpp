
// @Title: 同构字符串 (Isomorphic Strings)
// @Author: rubychen0611
// @Date: 2021-01-23 14:11:25
// @Runtime: 4 ms
// @Memory: 6.7 MB

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash_map1, hash_map2;
        for (int i = 0; i < s.length(); i++)
        {
            int ch1 = s[i], ch2 = t[i];
            unordered_map<char, char> ::iterator it1 = hash_map1.find(ch1), it2 = hash_map2.find(ch2);
            if (it1 == hash_map1.end() && it2 == hash_map2.end())
            {
                hash_map1[ch1] = ch2;
                hash_map2[ch2] = ch1;
            }
            else if (it1 == hash_map1.end() || it2 == hash_map2.end())
                return false;
            else if (it1 ->second != ch2 || it2 -> second != ch1)
                return false;
        }
        return true;

    }
};

