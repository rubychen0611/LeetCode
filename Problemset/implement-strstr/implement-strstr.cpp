
// @Title: 实现 strStr() (Implement strStr())
// @Author: rubychen0611
// @Date: 2021-02-13 19:05:59
// @Runtime: 0 ms
// @Memory: 6.9 MB

class Solution {
public:
    int strStr(string target, string pattern) {
        if(pattern == "")
            return 0;

        // 计算模式串的next数组
        vector<int> next(pattern.length(), 0);
        next[0] = -1;
        int i = 0, j = -1;
        while(i < pattern.length() - 1)
        {
            if(j == -1 || pattern[i] == pattern[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
                j = next[j];
        }

        // KMP模式匹配
        int t_pos = 0;  // 目标串指针
        int p_pos = 0;  // 模式串指针

        while(t_pos < (int)(target.length()) && p_pos < (int)(pattern.length()))
        {
            if(p_pos == -1 || target[t_pos] == pattern[p_pos])
            {
                t_pos ++;
                p_pos ++;
            }
            else
                p_pos = next[p_pos];
        }

        if(p_pos < pattern.length())    // 模式串未匹配完，匹配失败
            return -1;
        //cout<< t_pos << " " << pattern.length() << endl;
        return t_pos - pattern.length();

    }
};

