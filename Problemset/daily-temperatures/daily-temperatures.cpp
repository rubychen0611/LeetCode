
// @Title: 每日温度 (Daily Temperatures)
// @Author: rubychen0611
// @Date: 2020-12-23 21:12:50
// @Runtime: 128 ms
// @Memory: 39.1 MB

class Solution {
private:
    stack<int> st;
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            while(!st.empty() && T[st.top()] < T[i])
            {
                int j = st.top();
                ans[j] = i - j;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int j = st.top();
            ans[j] = 0;
            st.pop();
        }
        return ans;
    }
};

