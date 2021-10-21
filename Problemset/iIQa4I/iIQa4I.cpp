
// @Title: 每日温度 (每日温度)
// @Author: rubychen0611
// @Date: 2021-10-10 23:33:48
// @Runtime: 144 ms
// @Memory: 86.7 MB

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
