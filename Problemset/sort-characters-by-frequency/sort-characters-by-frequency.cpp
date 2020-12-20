
// @Title: 根据字符出现频率排序 (Sort Characters By Frequency)
// @Author: rubychen0611
// @Date: 2020-12-20 15:37:43
// @Runtime: 104 ms
// @Memory: 10.9 MB

class Solution {
public:
    string frequencySort(string s)
    {
        map<char,int> count_map;
        int max = 0;
        for (char c: s)
        {
            if(count_map.find(c) == count_map.end())
                count_map[c] = 1;
            else
                count_map[c] ++;
            if (count_map[c] > max)
                max = count_map[c];
        }
        vector<vector<char>> indexes(max+1, vector<char>());
        for(map<char,int>::iterator it=count_map.begin(); it != count_map.end(); it ++)
        {
            indexes[it->second].push_back(it->first);
        }
        int j = max;
        string ans = "";
        while(j > 0)
        {
            if (indexes[j].size() > 0)
            {
                for (int p = 0; p < indexes[j].size(); p++)
                    for (int q = 0; q < j; q++)
                        ans += indexes[j][p];
            }
            j--;
        }
        return ans;
    }

};

