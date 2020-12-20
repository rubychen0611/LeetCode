
// @Title: 颜色分类 (Sort Colors)
// @Author: rubychen0611
// @Date: 2020-12-20 15:56:57
// @Runtime: 4 ms
// @Memory: 8.6 MB

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int count[3] = {0};
        for(int x: nums)
        {
            count[x] ++;
        }
        int p = 0;
        for (int n = 0; n < 3; n++)
        {
            for(int i = 0; i < count[n]; i++)
                nums[p++] = n;
        }
    }
};

