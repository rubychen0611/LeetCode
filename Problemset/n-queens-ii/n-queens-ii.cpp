
// @Title: N皇后 II (N-Queens II)
// @Author: rubychen0611
// @Date: 2021-02-07 11:47:57
// @Runtime: 8 ms
// @Memory: 5.8 MB

class Solution {
private:
    int n;
    int ans;
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
            ans ++;
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
    int totalNQueens(int n) {
        this -> n = n;
        vector<int> queen_pos(n);
        ans = 0;
        backtrace(queen_pos, 0);
        return ans;
    }
};

