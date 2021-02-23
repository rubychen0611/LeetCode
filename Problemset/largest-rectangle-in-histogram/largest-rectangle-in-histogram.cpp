
// @Title: 柱状图中最大的矩形 (Largest Rectangle in Histogram)
// @Author: rubychen0611
// @Date: 2021-02-18 01:10:56
// @Runtime: 140 ms
// @Memory: 66.9 MB

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        // 前后加2个高度为0的柱子
        vector<int> new_heights = {0};
        new_heights.insert(new_heights.end(), heights.begin(), heights.end());
        new_heights.push_back(0);
        
        stack<int> st;
        int max = 0;
        for(int i = 0; i < new_heights.size(); i++)
        {
            while(!st.empty() && new_heights[st.top()] > new_heights[i])
            {
                int cur = st.top();     // 第cur个柱子找到了左右的第一个比其低的柱子
                st.pop();
                int left = st.top(), right = i;
                int s = (right - left - 1) * new_heights[cur];
                if(s > max)
                    max = s;
            }
            st.push(i);
        }

        return max;
    }
};
