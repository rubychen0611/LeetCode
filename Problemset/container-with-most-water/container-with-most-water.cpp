
// @Title: 盛最多水的容器 (Container With Most Water)
// @Author: rubychen0611
// @Date: 2021-02-17 13:29:37
// @Runtime: 24 ms
// @Memory: 17.3 MB

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int max = 0;
        while(i < j)
        {
            int water = (j - i) * min(height[i], height[j]);
            if(water > max)
                max = water;
            if(height[i] <= height[j])
                i++;
            else j--;
        }
        return max;
    }
};
