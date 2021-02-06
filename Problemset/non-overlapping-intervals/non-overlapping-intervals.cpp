
// @Title: 无重叠区间 (Non-overlapping Intervals)
// @Author: rubychen0611
// @Date: 2021-01-24 19:46:39
// @Runtime: 104 ms
// @Memory: 22.8 MB

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        int n = intervals.size();
        // 按结束时间排序
        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b)->bool{
            return a[1] < b[1];
        });
        int max = 1, last_end = intervals[0][1];
        for(int i = 1; i < n; i++)
        {
            if(intervals[i][0] >= last_end)
            {
                last_end = intervals[i][1];
                max ++;
            }
        }
        return n - max;
    }
};

