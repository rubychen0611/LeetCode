
// @Title: 安排会议日程 (Meeting Scheduler)
// @Author: rubychen0611
// @Date: 2021-02-14 17:26:26
// @Runtime: 212 ms
// @Memory: 39.1 MB

bool cmp(const vector<int> & slot1, const vector<int> & slot2)
{
    return slot1[0] < slot2[0];
}
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), cmp);
        sort(slots2.begin(), slots2.end(), cmp);
        int p1 = 0, p2 = 0;
        while(p1 < slots1.size() && p2 < slots2.size())
        {
            if(slots1[p1][1] - slots1[p1][0] < duration)
            {    
                p1 ++;
                continue;
            }
            if(slots2[p2][1] - slots2[p2][0] < duration)
            {
                p2 ++;
                continue;
            }    
            int start1 = slots1[p1][0], end1 = slots1[p1][1];
            int start2 = slots2[p2][0], end2 = slots2[p2][1];
            if(end2 <= start1) //没有交集
                p2++;
            else if(start2 >= end1) //没有交集
                p1++;
            else{       // 有交集
                int latest_start = max(start1, start2);
                int earliest_end = min(end1, end2);
                int free = earliest_end - latest_start;
                if(free >= duration)
                    return vector<int>{latest_start, latest_start + duration};
                if(end1 == earliest_end)
                    p1 ++;
                else p2 ++;    
            }
        }
        return vector<int>();
    }
};
