
// @Title: 滑动窗口的最大值 (滑动窗口的最大值 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-16 15:53:25
// @Runtime: 16 ms
// @Memory: 15.6 MB

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++)
        {
            int x = nums[i];
            while(!Q.empty() && Q.back() < x)
                Q.pop_back();
            Q.push_back(x);
            if(i >= k)
            {
                if(Q.front() == nums[i-k])
                    Q.pop_front();
                ans.push_back(Q.front());
            }
            if(i == k - 1)
                ans.push_back(Q.front());
            
        }
        return ans;
    }
};
