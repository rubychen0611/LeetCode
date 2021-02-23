
// @Title: 验证栈序列 (Validate Stack Sequences)
// @Author: rubychen0611
// @Date: 2021-02-16 14:14:08
// @Runtime: 16 ms
// @Memory: 15 MB

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int p = 0;  // pushed指针
        for(int i = 0; i < popped.size(); i++)
        {
            if(st.empty() || st.top() != popped[i])
            {
                while(p != pushed.size() && pushed[p] != popped[i]) // push直到popped[i]
                {
                    st.push(pushed[p]);
                    p++;
                }
                if(p == pushed.size())
                    return false;
                else
                {
                    st.push(pushed[p]);
                    p++;
                }
            }
            st.pop();
        }
        return true;
    }
};
