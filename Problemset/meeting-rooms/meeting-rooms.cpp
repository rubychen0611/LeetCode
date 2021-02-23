
// @Title: 会议室 (Meeting Rooms)
// @Author: rubychen0611
// @Date: 2021-02-17 15:30:56
// @Runtime: 28 ms
// @Memory: 11.4 MB

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return true;
        sort(intervals.begin(), intervals.end(), [](vector<int>& in1, vector<int>& in2) -> bool{
            return in1[0] < in2[0];
        });
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            if(intervals[i][1] > intervals[i+1][0])
                return false;
        }
        return true;
    }
};
