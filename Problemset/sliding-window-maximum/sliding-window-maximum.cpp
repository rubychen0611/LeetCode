
// @Title: 滑动窗口最大值 (Sliding Window Maximum)
// @Author: rubychen0611
// @Date: 2021-01-22 12:53:09
// @Runtime: 244 ms
// @Memory: 115.9 MB

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> d;   // 双端队列
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            // 加入新元素
            while(!d.empty() && d.back() < x)
            {
                d.pop_back();
            }

                d.push_back(x);
            if (i >= k) // 弹出最左元素
            {
                if (nums[i-k] == d.front())
                    d.pop_front();
            }
            if (i >= k - 1 && !d.empty())
                ans.push_back(d.front());
        }
        return ans;

    }
};

