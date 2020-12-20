
// @Title: 前 K 个高频元素 (Top K Frequent Elements)
// @Author: rubychen0611
// @Date: 2020-12-20 15:16:42
// @Runtime: 108 ms
// @Memory: 14 MB

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int,int> count_map;
        int max = 0;
        for (int x: nums)
        {
            if(count_map.find(x) == count_map.end())
                count_map[x] = 1;
            else
                count_map[x] ++;
            if (count_map[x] > max)
                max = count_map[x];
        }
        vector<vector<int>> indexes(max+1, vector<int>());
        for(map<int,int>::iterator it=count_map.begin(); it != count_map.end(); it ++)
        {
            indexes[it->second].push_back(it->first);
        }
        int j = max;
        vector<int> ans(k);
        for (int i = 0; i < k;)
        {
            while(indexes[j].size() == 0)
                j--;
            for (int p = 0; p < indexes[j].size(); p++)
                ans[i++] = indexes[j][p];
            j--;
        }
        return ans;
    }

};

