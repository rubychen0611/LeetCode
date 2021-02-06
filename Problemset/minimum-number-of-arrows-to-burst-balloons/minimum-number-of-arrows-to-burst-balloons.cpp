
// @Title: 用最少数量的箭引爆气球 (Minimum Number of Arrows to Burst Balloons)
// @Author: rubychen0611
// @Date: 2021-01-24 23:41:44
// @Runtime: 1032 ms
// @Memory: 162.2 MB

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
            return 0;
        int n = points.size();
        if (n == 1)
            return 1;
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) -> bool {
            return a[1] < b[1];
        });

        int ans = 1;
        int cur_end = points[0][1];
        for(int i = 1; i < n; i++)
        {
            if (points[i][0] <= cur_end)
                continue;
            else
            {
                cur_end = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};

