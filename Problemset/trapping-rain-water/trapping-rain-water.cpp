
// @Title: 接雨水 (Trapping Rain Water)
// @Author: rubychen0611
// @Date: 2021-10-12 11:22:08
// @Runtime: 16 ms
// @Memory: 15.6 MB

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        stack<int> st;
        int sum = 0;
        for(int i = 0; i < height.size(); i++) {
            while(!st.empty() && height[st.top()] <= height[i]) {
                int cur_h = height[st.top()];
                st.pop();
                while(!st.empty() && height[st.top()] == cur_h) {
                    st.pop();
                }
                if(!st.empty()) {
                    sum += (min(height[st.top()], height[i]) - cur_h) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return sum;
    }
};
