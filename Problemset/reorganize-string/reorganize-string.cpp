
// @Title: 重构字符串 (Reorganize String)
// @Author: rubychen0611
// @Date: 2021-02-17 17:50:46
// @Runtime: 0 ms
// @Memory: 6.2 MB

struct Info
{
    char ch;
    int count;
    Info(char c, int n): ch(c), count(n){}
    bool operator > (const Info &info) const
    {
        return count > info.count;
    }
};
class Solution {
public:
    string reorganizeString(string S) {
        vector<int> count(26, 0);
        for(const char & ch: S)
            count[ch - 'a'] ++;
        vector<Info> info;
        for(int i = 0; i < 26; i++)
        {
            if (count[i] > 0)
            {
                info.push_back(Info(i + 'a', count[i]));
            }
        }
        sort(info.begin(), info.end(), greater<Info>());
        int n = S.length();
        if(info[0].count > (n+1) / 2)
            return "";
        int j = 0;
        string ans(n, ' ');
        for(const Info &i: info)
        {
            int k = 0;
            while(j < n && k < i.count)
            {
                ans[j] = i.ch;
                j += 2;
                if(j >= n)
                    j = 1;
                k++;
            }
        }
        return ans;

    }
};
