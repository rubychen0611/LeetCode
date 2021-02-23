
// @Title: 会议室 II (Meeting Rooms II)
// @Author: rubychen0611
// @Date: 2021-02-17 16:03:54
// @Runtime: 20 ms
// @Memory: 11.5 MB

class Solution {
private:

public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> min_heap;
        // 按开始时间排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& in1, vector<int>& in2) -> bool{
            return in1[0] < in2[0];
        });
        min_heap.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(min_heap.top() <= intervals[i][0])
            {
                min_heap.pop();
                min_heap.push(intervals[i][1]);
            }
            else
                min_heap.push(intervals[i][1]);
        }
        return min_heap.size();
    }
};
