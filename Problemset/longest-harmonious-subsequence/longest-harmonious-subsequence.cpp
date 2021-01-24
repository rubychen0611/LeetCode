
// @Title: 最长和谐子序列 (Longest Harmonious Subsequence)
// @Author: rubychen0611
// @Date: 2021-01-22 19:57:20
// @Runtime: 112 ms
// @Memory: 40.7 MB

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count_map;
        int max = 0;
        for (int x: nums)
        {
            if (count_map.find(x) == count_map.end())
                count_map[x] = 1;
            else
                count_map[x] ++;
        }
        for(map<int,int> ::iterator it = count_map.begin(); it != prev(count_map.end()); it++)
        {
            map<int,int> ::iterator next_it = next(it);
           if (it -> first + 1 == next_it -> first)
           {
               int count = it -> second + next_it -> second;
               if (count > max)
                   max = count;
           }
        }
        return max;

    }
};

