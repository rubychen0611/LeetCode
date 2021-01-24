
// @Title: 数组的度 (Degree of an Array)
// @Author: rubychen0611
// @Date: 2021-01-22 19:29:09
// @Runtime: 56 ms
// @Memory: 24.4 MB

struct Info
{
    int count;
    int start, end;
    Info()
    {
        count = 0;
        start = 0;
        end = 0;
    }
    Info(int start)
    {
        count = 1;
        this->start = start;
        this->end = start;
    }
};
class Solution {
private:
    int getIntervalLength(Info& info)
    {
        return info.end - info.start + 1;
    }
public:
    int findShortestSubArray(vector<int>& nums)
    {
        unordered_map<int, Info> hash_map;
        int max = 0;
        vector<int> max_xs;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];

            if (hash_map.find(x) == hash_map.end())
            {
                hash_map[x] = Info(i);
            }
            else
            {
                hash_map[x].end = i;
                hash_map[x].count++;
            }
            //cout << x << " " <<hash_map[x].count << endl;
            if (hash_map[x].count > max)
            {
                max = hash_map[x].count;
                max_xs.clear();
                max_xs.push_back(x);
            }
            else if (hash_map[x].count == max)
                max_xs.push_back(x);
        }
        int min = getIntervalLength(hash_map[max_xs[0]]);
        if (max_xs.size() > 1)
        {
            for (int i = 1; i < max_xs.size(); i++)
            {
                int l = getIntervalLength(hash_map[max_xs[i]]);
                if (min > l)
                    min = l;
            }
        }
        return min;
    }
};

