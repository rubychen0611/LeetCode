
// @Title: 下一个更大元素 II (Next Greater Element II)
// @Author: rubychen0611
// @Date: 2021-01-22 17:49:02
// @Runtime: 36 ms
// @Memory: 22.3 MB

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int N = nums.size();
        if (N == 0)
            return vector<int>();
        else if (N == 1)
            return vector<int>{-1};

        stack<int> st;
        vector<int> ans(N, -1);
        st.push(0);
        int i = 1, idx, x;
        while(i < 2 * N)
        {
            idx = i % N;
            x = nums[idx];
            while(!st.empty() && x > nums[st.top()])
            {
                ans[st.top()] = x;
                st.pop();
            }
            if (!st.empty() && idx == st.top())
                break;
            if (ans[idx] == -1)
                st.push(idx);
            i ++;
        }
        return ans;
    }
};

