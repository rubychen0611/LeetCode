
// @Title: 接雨水 (Trapping Rain Water)
// @Author: rubychen0611
// @Date: 2021-02-17 13:14:02
// @Runtime: 12 ms
// @Memory: 14.1 MB

class Solution {
private:
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        int ans = 0;
        stack<int> st;  // 单调栈
        for(int i = 0; i < height.size(); i++)
        {
           while(!st.empty() && height[i] > height[st.top()])
           {
               int cur_h = height[st.top()];
               while(!st.empty() && height[st.top()] == cur_h)
                   st.pop();
               if (!st.empty())
               {
                   ans += (min(height[i], height[st.top()]) - cur_h) * (i - st.top() - 1);
               }
           }
           st.push(i);
        }

        return ans;
    }
};
