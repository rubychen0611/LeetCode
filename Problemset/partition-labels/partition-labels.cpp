
// @Title: 划分字母区间 (Partition Labels)
// @Author: rubychen0611
// @Date: 2021-01-25 00:19:58
// @Runtime: 8 ms
// @Memory: 6.3 MB

struct Info
{
    int first, last;
    Info(){first = last = 0;}
    Info(int f):first(f), last(f){}
};
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, Info> info_map;
        for(int i = 0; i < S.length(); i++)
        {
            char ch = S[i];
            if (info_map.find(ch) == info_map.end())
            {
                info_map[ch] = Info(i);
            }
            else
            {
                info_map[ch].last = i;
            }
        }
        int left = 0, right = info_map[S[0]].last;
        vector<int> ans;
        for(int i = 1; i < S.length(); i++)
        {
            const char & ch = S[i];
            if (info_map[ch].first > right)
            {
                ans.push_back(right - left + 1);
                left = info_map[ch].first;
                right = info_map[ch].last;
            }
            else if (info_map[ch].last > right)
                right = info_map[ch].last;

        }
        ans.push_back(right- left+1);
        return ans;
    }
};

