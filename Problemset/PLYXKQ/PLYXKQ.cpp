
// @Title: 矩阵中最大的矩形 (矩阵中最大的矩形)
// @Author: rubychen0611
// @Date: 2021-10-11 21:06:50
// @Runtime: 16 ms
// @Memory: 10.9 MB

class Solution {
private:
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
    int max(int a, int b) {
        return a > b ? a : b;
    }

public:
    int maximalRectangle(vector<string>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> hist(m, vector<int>(n, 0));
        int maxRect = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0) {
                        hist[i][j] = 1;
                    }
                    else {
                        hist[i][j] = hist[i-1][j] + 1;
                    }
                }
            }
            maxRect = max(maxRect, largestRectangleArea(hist[i]));
        }
        return maxRect;
    }
};
