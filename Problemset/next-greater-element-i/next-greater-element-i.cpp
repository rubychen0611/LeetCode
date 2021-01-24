
// @Title: 下一个更大元素 I (Next Greater Element I)
// @Author: rubychen0611
// @Date: 2021-01-22 17:17:40
// @Runtime: 4 ms
// @Memory: 8.6 MB

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> st;
        unordered_map<int, int> next_greater;
        for(int x: nums2)
        {
            while(!st.empty() && st.top() < x)
            {
                next_greater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        while(!st.empty())
        {
            next_greater[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for (int x: nums1)
        {
            ans.push_back(next_greater[x]);
        }
        return ans;
    }
};

