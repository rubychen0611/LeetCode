
// @Title: 有效的括号 (Valid Parentheses)
// @Author: rubychen0611
// @Date: 2020-12-23 20:54:26
// @Runtime: 4 ms
// @Memory: 6.6 MB

class Solution {
private:
    stack<char> st;
public:
    bool isValid(string s) {
        for(char ch : s)
        {
            switch (ch) {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                    if (st.empty())
                        return false;
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (st.empty())
                        return false;
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (st.empty())
                        return false;
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                    break;

            }
        }
        if (st.empty())
            return true;
        else return false;
    }
};

