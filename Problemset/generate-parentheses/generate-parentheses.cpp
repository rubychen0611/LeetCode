
// @Title: 括号生成 (Generate Parentheses)
// @Author: rubychen0611
// @Date: 2021-10-16 17:42:40
// @Runtime: 8 ms
// @Memory: 16.3 MB

class Solution {
private: 
    vector<string> ans;
    void backTrack(string str, int leftCount, int rightCount) {
        if(leftCount < 0 || rightCount < 0) {
            return;
        }
        if(leftCount == 0 && rightCount == 0) {
            ans.push_back(str);
        }
        if(leftCount == rightCount) {
            backTrack(str + '(', leftCount - 1, rightCount);
        }
        else if (leftCount < rightCount) {
            backTrack(str + '(', leftCount - 1, rightCount);
            backTrack(str + ')', leftCount, rightCount - 1);
            
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        stack<int> st;
        string str = "";
        backTrack(str, n, n);
        return ans;
    }
};
