
// @Title: 合并区间 (Merge Intervals)
// @Author: rubychen0611
// @Date: 2021-02-17 16:14:29
// @Runtime: 24 ms
// @Memory: 14.4 MB

class Solution {
private:
    bool overlap(const vector<int> &in1, const vector<int> &in2)
    {
        if(in1[1] < in2[0] || in2[1] < in1[0])
            return false;
        return true;
    }
    vector<int> mergeTwo(const vector<int> &in1, const vector<int> &in2)
    {
        int start = min(in1[0], in2[0]);
        int end = max(in1[1], in2[1]);
        return vector<int>{start, end};
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int>& in1, vector<int>& in2) -> bool{
            return in1[0] < in2[0];
        });
        vector<vector<int>> ans;
        vector<int> cur = intervals[0];
        for(int i = 1; i < n; i++)
        {
            if(overlap(cur, intervals[i]))
            {
                cur = mergeTwo(cur, intervals[i]);
            }
            else
            {
                ans.push_back(cur);
                cur = intervals[i];
            }
        }
        ans.push_back(cur);
        return ans;
    }
};
