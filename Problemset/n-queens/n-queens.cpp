
// @Title: N 皇后 (N-Queens)
// @Author: rubychen0611
// @Date: 2021-02-07 11:45:20
// @Runtime: 8 ms
// @Memory: 7.3 MB

class Solution {
private:
    int n;
    vector<vector<string>> answers;
    vector<string> generate_answer(vector<int> & queen_pos)
    {
        vector<string> ans(n, string(n, '.'));
        for(int i = 0; i < n; i++)
        {
            ans[i][queen_pos[i]] = 'Q';
        }
        return ans;
    }
    bool checkLegal(vector<int>& queen_pos, int x, int y)
    {
        if (x == 0)
            return true;
        for(int i = 0; i < x; i++)
        {
            if(queen_pos[i] == y)
                return false;
            if(abs(queen_pos[i] - y) == abs(x - i))
                return false;
        }
        return true;
    }
    void backtrace(vector<int>& queen_pos, int i)
    {
        if(i == n)
        {
            answers.push_back(generate_answer(queen_pos));
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(checkLegal(queen_pos, i, j))
            {
                queen_pos[i] = j;
                backtrace(queen_pos, i + 1);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        this -> n = n;
        vector<int> queen_pos(n);
        backtrace(queen_pos, 0);
        return answers;

    }
};

