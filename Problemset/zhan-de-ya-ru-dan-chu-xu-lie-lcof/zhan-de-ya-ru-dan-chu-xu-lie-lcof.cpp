
// @Title: 栈的压入、弹出序列 (栈的压入、弹出序列 LCOF)
// @Author: rubychen0611
// @Date: 2021-02-16 14:13:47
// @Runtime: 12 ms
// @Memory: 14.7 MB

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
