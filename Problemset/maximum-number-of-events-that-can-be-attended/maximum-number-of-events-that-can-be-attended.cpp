
// @Title: 最多可以参加的会议数目 (Maximum Number of Events That Can Be Attended)
// @Author: rubychen0611
// @Date: 2021-02-17 20:35:47
// @Runtime: 356 ms
// @Memory: 69.1 MB

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end(), [](vector<int> & e1, vector<int> &e2) -> bool{
            return e1[0] < e2[0];
        });
        priority_queue<int, vector<int>, greater<int>> min_heap;// 保存目前为止开始的活动
        int cur; // 下一个有空的时间
        int count = 0;
        
        int i = 0;
        while(i < events.size())
        {
            if(min_heap.empty())    // 加入第一个活动，cur为第一天
            {
                cur = events[i][0];
                min_heap.push(events[i][1]);
                i++;
                while(i < events.size() && events[i][0] == cur) // 加入和cur同时开始或之前开始的活动
                {
                    min_heap.push(events[i][1]);
                    i++;
                }
            }
            while(!min_heap.empty())  // 参加目前最早结束的活动
            {
                int earliest_end = min_heap.top();
                min_heap.pop();
                if(cur <= earliest_end)
                {
                    cur ++;
                    while(i < events.size() && events[i][0] <= cur) // 加入和cur同时开始或之前开始的活动
                    {
                        min_heap.push(events[i][1]);
                        i++;
                    }
                    count ++;
                }
            }
        }
        return count;
    }
};
