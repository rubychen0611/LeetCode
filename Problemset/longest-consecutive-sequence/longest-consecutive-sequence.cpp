
// @Title: 最长连续序列 (Longest Consecutive Sequence)
// @Author: rubychen0611
// @Date: 2021-01-22 13:54:58
// @Runtime: 8 ms
// @Memory: 10.3 MB

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if(nums.empty())
            return 0;
        unordered_set<int> hash_set;
        for (int x: nums)
            hash_set.insert(x);
        int max_len = 0, x, count;
        while(!hash_set.empty())
        {
            unordered_set<int>::iterator it = hash_set.begin();
            x = *(it);
            hash_set.erase(it);
            count = 1;
            int p = x + 1;
            it = hash_set.find(p);
            while(it != hash_set.end())
            {
                hash_set.erase(it);
                count ++;
                p++;
                it = hash_set.find(p);
            }
            p = x - 1;
            it = hash_set.find(p);
            while(it != hash_set.end())
            {
                hash_set.erase(it);
                count ++;
                p--;
                it = hash_set.find(p);
            }
            if (count > max_len)
                max_len = count;
        }
        return max_len;
    }
};

