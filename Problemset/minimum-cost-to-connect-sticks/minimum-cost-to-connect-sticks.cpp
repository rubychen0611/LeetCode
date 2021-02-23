
// @Title: 连接棒材的最低费用 (Minimum Cost to Connect Sticks)
// @Author: rubychen0611
// @Date: 2021-02-17 17:25:33
// @Runtime: 84 ms
// @Memory: 23.6 MB

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(int x: sticks)
        {
            min_heap.push(x);
        }
        int cost = 0;
        while(min_heap.size() > 1)
        {
            int x = min_heap.top();
            min_heap.pop();
            int y = min_heap.top();
            min_heap.pop();
            cost += x + y;
            min_heap.push(x + y);
        }
        return cost;
    }
};
