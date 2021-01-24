
// @Title: 最小覆盖子串 (Minimum Window Substring)
// @Author: rubychen0611
// @Date: 2021-01-05 17:20:22
// @Runtime: 124 ms
// @Memory: 8 MB

class Solution {
public:
    string minWindow(string s, string t)
    {
        set<char> t_chars;  // t中字母集合
        map<char, int> lack_map;   //目前缺少的t中字母数量
        for (char x : t)
        {
            t_chars.insert(x);
            if(lack_map.find(x) != lack_map.end())
                lack_map[x] ++;
            else
                lack_map[x] = 1;
        }

        int l = 0, r, min_l = 0, min_size = s.length()+1, cur_count = 0;
        for(r = 0; r < s.length(); r++)
        {
            char x = s[r];
            if(t_chars.find(x) != t_chars.end()) // t中有这个字母
            {
                lack_map[x] --;
                if (lack_map[x] >= 0)       // 目前正缺少这个字母
                    cur_count++;
            }

            while (cur_count == t.length())  // 不缺了
            {
                if(r - l + 1 < min_size)
                {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if(t_chars.find(s[l]) != t_chars.end())
                {
                    lack_map[s[l]] ++;
                    if(lack_map[s[l]] > 0)
                        cur_count --;
                }
                l++;
            }
        }
        if(min_size < s.length()+1)
            return s.substr(min_l, min_size);
        else return "";
    }
};

