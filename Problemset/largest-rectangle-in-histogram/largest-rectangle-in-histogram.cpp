
// @Title: 柱状图中最大的矩形 (Largest Rectangle in Histogram)
// @Author: rubychen0611
// @Date: 2021-10-11 20:45:57
// @Runtime: 120 ms
// @Memory: 61.8 MB

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        st.push(-1);
        int max = 0;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && st.top() >= 0 && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();
                int area = (i - st.top() - 1) * heights[cur];
                if(area > max) {
                    max = area;
                }
            }  
            st.push(i);
        }
        return max;
    }
};
